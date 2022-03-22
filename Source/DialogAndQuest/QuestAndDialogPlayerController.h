// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/QuestBearerInterface.h"
#include "QuestAndDialogPlayerController.generated.h"

/**
 *
 */
UCLASS()
class DIALOGANDQUEST_API AQuestAndDialogPlayerController : public APlayerController, public IQuestBearerInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	UQuestBearerComponent*  QuestBearerComponent= nullptr;


public:

	AQuestAndDialogPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable)
	virtual UQuestBearerComponent* GetQuestBearerComponent() override;

	UFUNCTION(BlueprintCallable)
	virtual const UQuestBearerComponent* GetQuestBearerComponentConst() const override;
};
