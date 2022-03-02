// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/DialogMainComponent.h"
#include "GameFramework/GameModeBase.h"
#include "DialogAndQuestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGANDQUEST_API ADialogAndQuestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Dialog")
	TObjectPtr<UDialogMainComponent> DialogComponent;

public:

	ADialogAndQuestGameModeBase();


	
};
