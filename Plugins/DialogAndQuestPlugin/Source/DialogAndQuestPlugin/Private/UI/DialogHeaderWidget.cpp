// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogHeaderWidget.h"

void UDialogHeaderWidget::InitDialog(UDialogWindow* InputParentDialog)
{
	ParentDialog = InputParentDialog;
	DialogComponent = InputParentDialog->GetDialogComponent();

	SetDialogName(DialogComponent->GetDialogName());
}