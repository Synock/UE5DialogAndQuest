// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "DialogWindow.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "DialogTopicButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGANDQUESTPLUGIN_API UDialogTopicButtonWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:

	UDialogWindow* ParentDialog = nullptr;


	
};
