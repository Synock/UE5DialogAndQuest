// Copyright 2022 Maximilien (Synock) Guislain


#include "Components/QuestBearerComponent.h"

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
	for(auto& QuestData : KnownQuestData)
	{
		if(!KnownQuestDataLUT.Contains(QuestData.QuestID))
			KnownQuestDataLUT.Add(QuestData.QuestID, LocalID);
		else
		{
			KnownQuestDataLUT[QuestData.QuestID] = LocalID;
		}
		++LocalID;
	}
}

void UQuestBearerComponent::Server_UpdateQuest_Implementation(int64 QuestID, int32 QuestStep)
{
	if(KnownQuestDataLUT.Contains(QuestID))
	{
		KnownQuestData[KnownQuestDataLUT[QuestID]].ProgressID = QuestStep;
	}
	else if(!KnownQuestDataLUT.Contains(QuestID) && QuestStep == 1)
	{
		//add the correct step
	}


	OnRep_KnownQuest();
}

bool UQuestBearerComponent::Server_UpdateQuest_Validate(int64 QuestID, int32 QuestStep)
{
	return true;
}

void UQuestBearerComponent::UpdateQuest(int64 QuestID, int32 QuestStep)
{
	Server_UpdateQuest_Validate(QuestID,QuestStep);
}

void UQuestBearerComponent::TryValidateQuestFromActor(int64 QuestID, AActor* QuestGiver)
{
	int32 CurrentStep = 0;
	if(KnownQuestDataLUT.Contains(QuestID))
	{
		CurrentStep = KnownQuestData[KnownQuestDataLUT[QuestID]].ProgressID;
	}

	IQuestGiverInterface* GiverInterface = Cast<IQuestGiverInterface>(QuestGiver);

	if(GiverInterface)
	{
		if(GiverInterface->GetQuestGiverComponent()->CanValidateQuestStep(QuestID, CurrentStep))
		{
			if(CurrentStep == 0)
			{
				KnownQuestData[KnownQuestDataLUT[QuestID]].ProgressID = 10;
				//KnownQuestData.Add()
				//TODO RESTART FROM HERE
			}
			else
			{
				KnownQuestData[KnownQuestDataLUT[QuestID]].ProgressID = CurrentStep + 10;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestBearerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(UQuestBearerComponent, KnownQuestData, COND_OwnerOnly);
}
