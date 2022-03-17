// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestData.generated.h"

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

USTRUCT(BlueprintType)
struct FQuestValidableSteps
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	int64 QuestID = 0;

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Steps;
};

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

	UPROPERTY(BlueprintReadOnly)
	TArray<FQuestStep> PreviousStep;
};

///global quest Data
UCLASS(BlueprintType)
class DIALOGANDQUESTPLUGIN_API UQuestJournalData : public UObject
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