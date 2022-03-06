// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogWindow.h"

#include "UI/DialogFooterWidget.h"
#include "UI/DialogHeaderWidget.h"
#include "UI/DialogTextWidget.h"
#include "UI/DialogTopicWidget.h"

void UDialogWindow::InitDialogWindow(UDialogComponent* InputDialogComponent)
{
	DialogComponent = InputDialogComponent;

	InitDialogUI();
	Footer->InitDialog(this);
	Header->InitDialog(this);
	TopicText->InitDialog(this);
	TopicList->InitDialog(this);
}

void UDialogWindow::DisplayDialogTopic(int64 ID)
{
	TopicText->AddTopicText(ID);
}

