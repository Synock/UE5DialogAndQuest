// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "DialogWindow.h"
#include "Blueprint/UserWidget.h"
#include "DialogHeaderWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGANDQUESTPLUGIN_API UDialogHeaderWidget : public UUserWidget
{
	GENERATED_BODY()
protected:

	UDialogWindow* ParentDialog = nullptr;
	const UDialogComponent* DialogComponent = nullptr;

public:

	UFUNCTION(BlueprintCallable)
	void InitDialog(UDialogWindow* InputParentDialog);

	UFUNCTION(BlueprintImplementableEvent)
	void SetDialogName(const FString & Name);

	UFUNCTION(BlueprintImplementableEvent)
	void SetRelationValue(float RelationFloat);

};
