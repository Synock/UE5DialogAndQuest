// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Components/QuestBearerComponent.h"
#include "UObject/Interface.h"
#include "QuestBearerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UQuestBearerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class DIALOGANDQUESTPLUGIN_API IQuestBearerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual UQuestBearerComponent* GetQuestBearerComponent() = 0;
};
