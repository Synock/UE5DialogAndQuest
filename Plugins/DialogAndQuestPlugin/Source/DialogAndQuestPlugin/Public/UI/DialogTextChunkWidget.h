// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "DialogTextChunkWidget.generated.h"

USTRUCT(BlueprintType)
struct FDialogTextData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int64 Id;

	UPROPERTY(BlueprintReadWrite)
	FString TopicName;

	UPROPERTY(BlueprintReadWrite)
	FString TopicText;
};

UCLASS(BlueprintType)
class DIALOGANDQUESTPLUGIN_API UDialogTextChunkData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FDialogTextData Data;
};


/**
 * 
 */
UCLASS()
class DIALOGANDQUESTPLUGIN_API UDialogTextChunkWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void InitData(const FDialogTextData& ItemData);

	UPROPERTY(BlueprintReadOnly)
	int64 ItemID;
};
