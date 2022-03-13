// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestData.h"
#include "UObject/Object.h"
#include "DialogData.generated.h"


USTRUCT(BlueprintType)
struct FDialogTopicCondition
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float MinimumRelation = 0.375f;

	bool VerifyCondition(const AActor* DialogActor) const;
	
};

USTRUCT(BlueprintType)
struct FDialogTopicStruct
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int64 Id = 0;

	UPROPERTY(BlueprintReadWrite)
	FString Topic;

	UPROPERTY(BlueprintReadWrite)
	FDialogTopicCondition TopicCondition;

	UPROPERTY(BlueprintReadWrite)
	FString TopicText;

	UPROPERTY(BlueprintReadWrite)
	FQuestValidableSteps QuestRelation;
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

	UPROPERTY(BlueprintReadWrite)
	FString GoodGreetingDialog = "Greetings";

	UPROPERTY(BlueprintReadWrite)
	FString BadGreetingDialog = "I don't wish to speak to your kind. Now get lost!";

	UPROPERTY(BlueprintReadWrite)
	float MinimumRelation = 0.375;

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
