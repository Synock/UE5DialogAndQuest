// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "DialogActor.h"
#include "Components/QuestGiverComponent.h"
#include "Interfaces/QuestGiverInterface.h"
#include "QuestDialogActor.generated.h"

UCLASS()
class DIALOGANDQUEST_API AQuestDialogActor : public ADialogActor, public IQuestGiverInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestDialogActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UQuestGiverComponent> QuestComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UQuestGiverComponent* GetQuestGiverComponent() const override;
};
