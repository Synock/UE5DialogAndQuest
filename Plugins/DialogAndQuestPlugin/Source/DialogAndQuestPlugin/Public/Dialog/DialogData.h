// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogData.generated.h"




USTRUCT(BlueprintType)
struct FDialogTopicStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int64 Id = 0;

	UPROPERTY(BlueprintReadWrite)
	FString Topic;

	UPROPERTY(BlueprintReadWrite)
	FString TopicText;
};

USTRUCT(BlueprintType)
struct FDialogTopicBundleStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int64 Id = 0;

	TArray<int64> TopicList;

	UPROPERTY(BlueprintReadWrite)
	FString MetaName;

};

USTRUCT(BlueprintType)
struct FDialogTopicMetaBundleStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int64 Id = 0;

	TArray<int64> TopicBundleList;

	UPROPERTY(BlueprintReadWrite)
	FString MetaName;

};

/**
 *
 */
UCLASS()
class DIALOGANDQUESTPLUGIN_API UDialogData : public UObject
{
	GENERATED_BODY()
};
