// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/DialogMainComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/DialogGameModeInterface.h"
#include "DialogAndQuestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGANDQUEST_API ADialogAndQuestGameModeBase : public AGameModeBase, public IDialogGameModeInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Dialog")
	TObjectPtr<UDialogMainComponent> DialogComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Quest")
	TObjectPtr<UQuestMainComponent> QuestComponent;

public:

	ADialogAndQuestGameModeBase();

	virtual UDialogMainComponent* GetMainDialogComponent() override {return DialogComponent;}

	virtual UQuestMainComponent* GetMainQuestComponent() override { return QuestComponent;}
};
