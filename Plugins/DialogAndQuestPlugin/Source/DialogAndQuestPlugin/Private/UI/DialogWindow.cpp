// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogWindow.h"

void UDialogWindow::InitDialogWindow(UDialogComponent* InputDialogComponent)
{
	DialogComponent = InputDialogComponent;
	InitDialogUI(InputDialogComponent);
}

