// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Quest/QuestData.h"
#include "QuestBearerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FKnownQuestChanged);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DIALOGANDQUESTPLUGIN_API UQuestBearerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UQuestBearerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(ReplicatedUsing=OnRep_KnownQuest, BlueprintReadWrite)
	TArray<FQuestProgressData> KnownQuestData;

	UPROPERTY(BlueprintReadWrite)
	TMap<int64, int32> KnownQuestDataLUT;

	UFUNCTION()
	void OnRep_KnownQuest();

	UFUNCTION(Server,Reliable,WithValidation)
	void Server_UpdateQuest(int64 QuestID, int32 QuestStep);

public:

	const TArray<FQuestProgressData>& GetAllKnownQuest() const { return KnownQuestData; }

	UPROPERTY(BlueprintAssignable) //this is public because its a dispatcher
	FKnownQuestChanged KnownQuestDispatcher;

	UFUNCTION(BlueprintCallable)
	void UpdateQuest(int64 QuestID, int32 QuestStep);

	UFUNCTION(BlueprintCallable)
    void TryValidateQuestFromActor(int64 QuestID, AActor* QuestGiver);
};
