// Copyright 2022 Maximilien (Synock) Guislain


#include "Components/QuestGiverComponent.h"


// Sets default values for this component's properties
UQuestGiverComponent::UQuestGiverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

//----------------------------------------------------------------------------------------------------------------------

// Called when the game starts
void UQuestGiverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestGiverComponent::AddValidableSteps(int64 QuestID, TArray<int32> Steps)
{
	FQuestValidableSteps localData;
	localData.QuestID = QuestID;
	localData.Steps = Steps;

	ValidableSteps.Add(QuestID,std::move(localData));
}

//----------------------------------------------------------------------------------------------------------------------

bool UQuestGiverComponent::CanValidateQuestStep(int64 QuestID, int32 CurrentQuestStep)
{
	const ENetRole localRole = GetOwnerRole();
	if(localRole != ROLE_Authority)
		return false;

	if (!ValidableSteps.Contains(QuestID))
		return false;

	if (ValidableSteps.FindChecked(QuestID).Steps.Contains(CurrentQuestStep))
		return true;

	return false;
}
