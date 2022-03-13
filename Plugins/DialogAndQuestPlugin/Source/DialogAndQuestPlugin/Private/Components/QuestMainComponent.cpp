// Copyright 2022 Maximilien (Synock) Guislain


#include "Components/QuestMainComponent.h"


// Sets default values for this component's properties
UQuestMainComponent::UQuestMainComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UQuestMainComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UQuestMainComponent::AddQuest(const FQuestMetaData& QuestData)
{
	if(GetOwnerRole() != ROLE_Authority)
		return;

	QuestList.Add(QuestData.QuestID, QuestData);
}

const FQuestMetaData& UQuestMainComponent::GetQuestData(int64 QuestID) const
{
	return QuestList.FindChecked(QuestID);
}
