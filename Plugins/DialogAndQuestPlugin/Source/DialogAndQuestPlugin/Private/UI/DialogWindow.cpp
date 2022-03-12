// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogWindow.h"

#include "Interfaces/DialogInterface.h"
#include "UI/DialogFooterWidget.h"
#include "UI/DialogHeaderWidget.h"
#include "UI/DialogTextWidget.h"
#include "UI/DialogTopicWidget.h"

void UDialogWindow::InitDialogWindow(UDialogComponent* InputDialogComponent, AActor* ActorDialog)
{
	DialogComponent = InputDialogComponent;
	DialogActor = ActorDialog;

	InitDialogUI();
	Footer->InitDialog(this);
	Header->InitDialog(this);
	TopicText->InitDialog(this);
	TopicList->InitDialog(this);

	IDialogInterface* DialogActorInterface = Cast<IDialogInterface>(DialogActor);
	if(DialogActor && DialogActorInterface)
	{
		RelationValue = DialogActorInterface->GetRelation();
		RelationString = DialogActorInterface->GetRelationString(RelationValue);
	}
	else
	{
		PostInitRelation();
	}

	Header->SetRelationValue(RelationValue);
	Header->SetRelationString(RelationString);

}

void UDialogWindow::DisplayDialogTopic(int64 ID)
{
	TopicText->AddTopicText(ID);
}

void UDialogWindow::DisplayDialogTopicFromString(const FString& ID)
{
	TopicText->AddTopicText(DialogComponent->GetDialogTopicID(ID));
}

void UDialogWindow::CloseWindow()
{
	RemoveFromParent();
}

