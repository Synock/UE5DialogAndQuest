// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogTopicWidget.h"

void UDialogTopicWidget::InitDialog(UDialogWindow* InputParentDialog)
{
	ParentDialog = InputParentDialog;
	DialogComponent = InputParentDialog->GetDialogComponent();
}
