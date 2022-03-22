// Copyright 2022 Maximilien (Synock) Guislain


#include "Components/QuestBearerComponent.h"

#include "Interfaces/DialogGameModeInterface.h"
#include "Interfaces/QuestGiverInterface.h"
#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
UQuestBearerComponent::UQuestBearerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

//----------------------------------------------------------------------------------------------------------------------

// Called when the game starts
void UQuestBearerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestBearerComponent::OnRep_KnownQuest()
{
	KnownQuestDispatcher.Broadcast();

	int32 LocalID = 0;
	for (const auto& QuestData : KnownQuestData)
	{
		if (!KnownQuestDataLUT.Contains(QuestData.QuestID))
			KnownQuestDataLUT.Add(QuestData.QuestID, LocalID);
		else
		{
			KnownQuestDataLUT[QuestData.QuestID] = LocalID;
		}
		++LocalID;
	}
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestBearerComponent::Server_UpdateQuest_Implementation(int64 QuestID, int32 QuestStep, AActor* QuestGiver)
{
	if (const IQuestGiverInterface* GiverInterface = Cast<IQuestGiverInterface>(QuestGiver))
	{
		if (GiverInterface->GetQuestGiverComponent()->CanValidateQuestStep(QuestID, QuestStep))
		{
			if (QuestStep == 0 && !KnownQuestDataLUT.Contains(QuestID))
			{
				IDialogGameModeInterface* IDialogInterface = Cast<IDialogGameModeInterface>(
					GetWorld()->GetAuthGameMode());

				check(IDialogInterface);

				FQuestMetaData QuestData = IDialogInterface->GetMainQuestComponent()->GetQuestData(QuestID);
				FQuestProgressData NewQuestData;
				NewQuestData.Repeatable = QuestData.Repeatable;
				NewQuestData.QuestTitle = QuestData.QuestTitle;
				NewQuestData.QuestID = QuestData.QuestID;
				NewQuestData.ProgressID = 0;
				NewQuestData.CurrentStep = {QuestData.Steps[0], false};
				KnownQuestData.Add(std::move(NewQuestData));

				KnownQuestDataLUT.Add(QuestData.QuestID, KnownQuestData.Num() - 1);
			}
			else if (auto& QData = KnownQuestData[KnownQuestDataLUT[QuestID]]; QuestStep != QData.ProgressID)
			{
				QData.CurrentStep.Completed = true;
				QData.PreviousStep.Add(std::move(QData.CurrentStep));
				QData.ProgressID = QuestStep;

				IDialogGameModeInterface* IDialogInterface = Cast<IDialogGameModeInterface>(
					GetWorld()->GetAuthGameMode());
				check(IDialogInterface);
				FQuestMetaData QuestCompleteData = IDialogInterface->GetMainQuestComponent()->GetQuestData(QuestID);

				QData.CurrentStep = {QuestCompleteData.Steps[QuestStep], false};
			}
		}
	}


	OnRep_KnownQuest();
}

//----------------------------------------------------------------------------------------------------------------------

bool UQuestBearerComponent::Server_UpdateQuest_Validate(int64 QuestID, int32 QuestStep, AActor* QuestGiver)
{
	IQuestGiverInterface* GiverInterface = Cast<IQuestGiverInterface>(QuestGiver);

	if (!GiverInterface)
		return false;

	if (!GiverInterface->GetQuestGiverComponent())
		return false;

	if (!GiverInterface->GetQuestGiverComponent()->CanValidateQuestStep(QuestID, QuestStep))
		return false;

	return true;
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestBearerComponent::UpdateQuest(int64 QuestID, int32 QuestStep, AActor* QuestGiver)
{
	Server_UpdateQuest(QuestID, QuestStep, QuestGiver);
}

//----------------------------------------------------------------------------------------------------------------------

const FQuestProgressData& UQuestBearerComponent::GetKnownQuest(int64 QuestID) const
{
	return KnownQuestData[KnownQuestDataLUT.FindChecked(QuestID)];
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestBearerComponent::TryValidateQuestFromActor(int64 QuestID, AActor* QuestGiver)
{
	int32 CurrentStep = 0;
	if (KnownQuestDataLUT.Contains(QuestID))
	{
		CurrentStep = KnownQuestData[KnownQuestDataLUT[QuestID]].ProgressID;
	}

	if (IQuestGiverInterface* GiverInterface = Cast<IQuestGiverInterface>(QuestGiver); !GiverInterface)
		return;

	//if (GiverInterface->GetQuestGiverComponent()->CanValidateQuestStep(QuestID, CurrentStep))
	UpdateQuest(QuestID, CurrentStep, QuestGiver);
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestBearerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(UQuestBearerComponent, KnownQuestData, COND_OwnerOnly);
}
