// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/QuestJournal/QuestJournalWindow.h"

#include "Interfaces/QuestBearerInterface.h"

void UQuestJournalWindow::UpdateKnownQuest()
{
	ListWidget->UpdateQuestList();
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestJournalWindow::InitJournal()
{
	if(IQuestBearerInterface* QuestBearer = Cast<IQuestBearerInterface>(GetOwningPlayer()))
	{
		QuestComponent = QuestBearer->GetQuestBearerComponent();
		QuestComponent->KnownQuestDispatcher.AddDynamic(this, &UQuestJournalWindow::UpdateKnownQuest);
	}

	ListWidget->InitDialog(this);
	DetailsWidget->InitDialog(this);
}

//----------------------------------------------------------------------------------------------------------------------

void UQuestJournalWindow::DisplayQuest(int64 ID)
{
	DetailsWidget->DisplayQuestData(ID);
}
