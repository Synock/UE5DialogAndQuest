// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogTopicWidget.h"


void UDialogTopicWidget::InitDialog(UDialogWindow* InputParentDialog)
{
	ParentDialog = InputParentDialog;
	DialogComponent = InputParentDialog->GetDialogComponent();
}

void UDialogTopicWidget::UpdateTopicData()
{
	ClearList();
	for (auto& Topic : DialogComponent->GetAllDialogTopic())
	{
		FDialogTextData TextData;
		TextData.Id = Topic.Id;
		TextData.TopicName = Topic.Topic;
		TextData.TopicText = Topic.TopicText;
		AddTopicData(TextData);
	}
}
