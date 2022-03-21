// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestData.generated.h"

///represent a quest objective, eg, go to the bakery, talk to somebody, bring 10 wolf fang
USTRUCT(BlueprintType)
struct FQuestStep
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int64 QuestID = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 QuestSubID = 0;

	UPROPERTY(BlueprintReadOnly)
	FString StepTitle;

	UPROPERTY(BlueprintReadOnly)
	FString StepDescription;
};

/// This is a complete quest
USTRUCT(BlueprintType)
struct FQuestMetaData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int64 QuestID = 0;

	UPROPERTY(BlueprintReadOnly)
	FString QuestTitle;

	UPROPERTY(BlueprintReadOnly)
	bool Repeatable = false;

	UPROPERTY(BlueprintReadOnly)
	TArray<FQuestStep> Steps;
};

///This is a list of objectives that can be validated
USTRUCT(BlueprintType)
struct FQuestValidableSteps
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int64 QuestID = 0;

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Steps;
};


///This is a quest from the player perspective
USTRUCT(BlueprintType)
struct FQuestProgressData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int64 QuestID = 0;

	UPROPERTY(BlueprintReadOnly)
	int32 ProgressID = 0;

	UPROPERTY(BlueprintReadOnly)
	bool Finished = false;

	UPROPERTY(BlueprintReadOnly)
	bool Repeatable = false;

	UPROPERTY(BlueprintReadOnly)
	FQuestStep CurrentStep;

	UPROPERTY(BlueprintReadOnly)
	FString QuestTitle;

	///steps already done by the player
	UPROPERTY(BlueprintReadOnly)
	TArray<FQuestStep> PreviousStep;
};

///Global quest Data
UCLASS(BlueprintType)
class DIALOGANDQUESTPLUGIN_API UQuestJournalTitleData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FQuestProgressData Data;

	UPROPERTY(BlueprintReadWrite)
	class UQuestJournalWindow* Parent = nullptr;
};

///quest Step entry
UCLASS(BlueprintType)
class DIALOGANDQUESTPLUGIN_API UQuestEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FQuestStep Data;

	UPROPERTY(BlueprintReadWrite)
	bool Finished;

	UPROPERTY(BlueprintReadWrite)
	UQuestJournalWindow* Parent = nullptr;
};