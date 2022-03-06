// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogTextWidget.h"

void UDialogTextWidget::InitDialog(UDialogWindow* InputParentDialog)
{
	ParentDialog = InputParentDialog;
	DialogComponent = InputParentDialog->GetDialogComponent();
}

void UDialogTextWidget::AddTopicText(int64 TopicID)
{
	const FDialogTopicStruct& Topic = DialogComponent->GetDialogTopic(TopicID);
	FDialogTextData TextData;
	TextData.Id = Topic.Id;
	TextData.TopicName = Topic.Topic;
	TextData.TopicText = Topic.TopicText;
	AddTopicData(TextData);
}
