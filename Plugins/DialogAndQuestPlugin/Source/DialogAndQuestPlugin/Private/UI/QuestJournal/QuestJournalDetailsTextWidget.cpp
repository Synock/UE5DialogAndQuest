// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/QuestJournal/QuestJournalDetailsTextWidget.h"

void UQuestJournalDetailsTextWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (const UQuestEntryData* Data = Cast<UQuestEntryData>(ListItemObject))
	{
		LocalData = Data->Data;
		ParentJournal = Data->Parent;
		InitData(Data->Data);
	}
}
