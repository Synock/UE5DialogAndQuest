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


// Called when the game starts
void UQuestGiverComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

bool UQuestGiverComponent::CanValidateQuestStep(int64 QuestID, int32 CurrentQuestStep)
{
	if(!ValidableSteps.Contains(QuestID))
		return false;

	if(ValidableSteps.FindChecked(QuestID).Steps.Contains(CurrentQuestStep))
		return true;

	return false;
}

