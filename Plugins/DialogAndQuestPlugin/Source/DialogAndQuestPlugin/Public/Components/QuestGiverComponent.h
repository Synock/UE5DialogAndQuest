// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Quest/QuestData.h"
#include "QuestGiverComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DIALOGANDQUESTPLUGIN_API UQuestGiverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestGiverComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<int64, FQuestValidableSteps> ValidableSteps;


	void TryValidateQuestStep(int64 QuestID);

public:

	bool CanValidateQuestStep(int64 QuestID, int32 CurrentQuestStep);


};
