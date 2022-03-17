// Copyright 2022 Maximilien (Synock) Guislain


#include "Dialog/DialogData.h"

#include "Interfaces/DialogInterface.h"

bool FDialogTopicCondition::VerifyCondition(const AActor* DialogActor) const
{
	if (const IDialogInterface* DialogInterfaceActor = Cast<IDialogInterface>(DialogActor))
		return DialogInterfaceActor->GetRelation() >= MinimumRelation;

	return false;
}
