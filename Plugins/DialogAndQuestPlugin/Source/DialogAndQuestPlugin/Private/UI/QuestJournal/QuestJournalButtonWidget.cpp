// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/QuestJournal/QuestJournalButtonWidget.h"

void UQuestJournalButtonWidget::InitParent(UQuestJournalWindow* Parent)
{
	ParentJournal = Parent;
}

void UQuestJournalButtonWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
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
