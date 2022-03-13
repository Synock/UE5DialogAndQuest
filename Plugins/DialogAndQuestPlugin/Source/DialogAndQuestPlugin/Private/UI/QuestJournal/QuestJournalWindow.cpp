// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/QuestJournal/QuestJournalWindow.h"

#include "Interfaces/QuestBearerInterface.h"

void UQuestJournalWindow::UpdateKnownQuest()
{
	ListWidget->UpdateQuestList();
}

void UQuestJournalWindow::InitJournal()
{

	IQuestBearerInterface* QuestBearer = Cast<IQuestBearerInterface>(GetOwningLocalPlayer());

	if(QuestBearer)
	{
		QuestComponent = QuestBearer->GetQuestBearerComponent();
		QuestComponent->KnownQuestDispatcher.AddDynamic(this, &UQuestJournalWindow::UpdateKnownQuest);
	}
}
