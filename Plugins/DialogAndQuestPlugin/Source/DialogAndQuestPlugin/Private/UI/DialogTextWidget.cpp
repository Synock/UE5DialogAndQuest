// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogTextWidget.h"

void UDialogTextWidget::InitDialog(UDialogWindow* InputParentDialog)
{
	ParentDialog = InputParentDialog;
	DialogComponent = InputParentDialog->GetDialogComponent();
}