// Copyright 2022 Maximilien (Synock) Guislain


#include "QuestAndDialogPlayerController.h"

AQuestAndDialogPlayerController::AQuestAndDialogPlayerController(const FObjectInitializer& ObjectInitializer)
{
	QuestBearerComponent = CreateDefaultSubobject<UQuestBearerComponent>(TEXT("QuestBearerComponent"));
	QuestBearerComponent->SetIsReplicated(true);
}

UQuestBearerComponent* AQuestAndDialogPlayerController::GetQuestBearerComponent()
{
	return QuestBearerComponent;
}
