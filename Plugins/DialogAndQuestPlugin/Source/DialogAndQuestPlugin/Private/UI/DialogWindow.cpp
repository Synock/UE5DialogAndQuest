// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/DialogWindow.h"

#include "Interfaces/DialogInterface.h"
#include "Interfaces/QuestBearerInterface.h"
#include "Interfaces/QuestGiverInterface.h"
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

	if(RelationValue >= DialogComponent->GetGreetingLimit())
		TopicText->AddEmptyTopicData(DialogComponent->GetGoodGreeting());
	else
		TopicText->AddEmptyTopicData(DialogComponent->GetBadGreeting());


}

void UDialogWindow::DisplayDialogTopic(int64 ID)
{
	TopicText->AddTopicText(ID);
	//also try to update possible quest advancement here?

	IQuestGiverInterface* GiverInterface = Cast<IQuestGiverInterface>(DialogActor);

	if(GiverInterface)
	{
		const FDialogTopicStruct& Topic = DialogComponent->GetDialogTopic(ID);

		IQuestBearerInterface* BearerInterface = Cast<IQuestBearerInterface>(GetOwningPlayer());

		if(BearerInterface)
		{
			if(Topic.QuestRelation.QuestID != 0)
			{

			}
		}
	}
}

void UDialogWindow::DisplayDialogTopicFromString(const FString& ID)
{
	DisplayDialogTopic(DialogComponent->GetDialogTopicID(ID));
}

void UDialogWindow::CloseWindow()
{
	RemoveFromParent();
}

