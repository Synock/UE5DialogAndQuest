// Copyright 2022 Maximilien (Synock) Guislain


#include "QuestAndDialogPlayerController.h"

AQuestAndDialogPlayerController::AQuestAndDialogPlayerController(const FObjectInitializer& ObjectInitializer)
{
	if(HasAuthority())
	{
		QuestBearerComponent = CreateDefaultSubobject<UQuestBearerComponent>(TEXT("QuestBearerComponent"));
		QuestBearerComponent->SetIsReplicated(true);
		QuestBearerComponent->SetNetAddressable();
	}
}

UQuestBearerComponent* AQuestAndDialogPlayerController::GetQuestBearerComponent()
{
	return QuestBearerComponent;
}

const UQuestBearerComponent* AQuestAndDialogPlayerController::GetQuestBearerComponentConst() const
{
	return QuestBearerComponent;
}