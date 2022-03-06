// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/DialogComponent.h"
#include "DialogWindow.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExitEvent);

/**
 * 
 */
UCLASS()
class DIALOGANDQUESTPLUGIN_API UDialogWindow : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite)
	UDialogComponent* DialogComponent = nullptr;

	UPROPERTY(BlueprintReadWrite)
	class UDialogFooterWidget* Footer = nullptr;

	UPROPERTY(BlueprintReadWrite)
	class UDialogHeaderWidget* Header = nullptr;

	UPROPERTY(BlueprintReadWrite)
	class UDialogTopicWidget* TopicList = nullptr;

	UPROPERTY(BlueprintReadWrite)
	class UDialogTextWidget* TopicText = nullptr;

public:
	UFUNCTION(BlueprintCallable)
	const UDialogComponent* GetDialogComponent() const { return DialogComponent; }

	UFUNCTION(BlueprintCallable)
	void InitDialogWindow(UDialogComponent* InputDialogComponent);

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void InitDialogUI();

	UFUNCTION(BlueprintCallable)
	void DisplayDialogTopic(int64 ID);

	UPROPERTY(BlueprintAssignable)
	FOnExitEvent OnExit;
};
