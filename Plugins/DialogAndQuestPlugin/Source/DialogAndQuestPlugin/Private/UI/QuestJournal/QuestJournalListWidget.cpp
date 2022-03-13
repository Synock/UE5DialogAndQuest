// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/QuestJournal/QuestJournalListWidget.h"
#include "UI/QuestJournal/QuestJournalWindow.h"

void UQuestJournalListWidget::InitDialog(UQuestJournalWindow* InputParentDialog)
{
	ParentJournal = InputParentDialog;
	QuestBearerComponent = InputParentDialog->GetQuestComponent();
}

void UQuestJournalListWidget::UpdateQuestList()
{
	ClearList();


	for (auto& QuestData : QuestBearerComponent->GetAllKnownQuest())
	{
		if (!QuestData.Finished)
		{
			AddQuestTitleData(QuestData);
		}
	}
}
