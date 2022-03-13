// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/QuestJournal/QuestJournalDetailsTextWidget.h"

void UQuestJournalDetailsTextWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	UQuestJournalData* Data = Cast<UQuestJournalData>(ListItemObject);

	if (Data)
	{
		LocalData = Data->Data;
		ParentJournal = Data->Parent;
		InitData(Data->Data);
	}
}
