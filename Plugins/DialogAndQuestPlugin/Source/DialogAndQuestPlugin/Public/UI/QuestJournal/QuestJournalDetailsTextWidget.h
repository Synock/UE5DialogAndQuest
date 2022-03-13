// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Quest/QuestData.h"
#include "QuestJournalDetailsTextWidget.generated.h"

/**
 *
 */
UCLASS()
class DIALOGANDQUESTPLUGIN_API UQuestJournalDetailsTextWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void InitData(const FQuestProgressData& ItemData);

	UPROPERTY(BlueprintReadOnly)
	int64 ItemID = 0;

	UPROPERTY(BlueprintReadOnly)
	FQuestProgressData LocalData;

	UPROPERTY(BlueprintReadOnly)
	UQuestJournalWindow* ParentJournal = nullptr;

public:

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
