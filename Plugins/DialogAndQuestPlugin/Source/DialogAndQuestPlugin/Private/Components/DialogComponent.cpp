// Copyright 2022 Maximilien (Synock) Guislain


#include "Components/DialogComponent.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/DialogGameModeInterface.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UDialogComponent::UDialogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


TArray<FDialogTopicStruct> UDialogComponent::GetAllDialogTopic() const
{
	TArray<FDialogTopicStruct> Output;

	for(auto& Data : DialogTopic)
	{
		Output.Add(Data.Value);
	}

	return Output;
}

// Called when the game starts
void UDialogComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UDialogComponent::InitDialogFromID(int64 ID)
{
	TArray<FDialogTopicStruct> FullDialog;
		IDialogGameModeInterface* GM = Cast<IDialogGameModeInterface>(UGameplayStatics::GetGameMode(GetWorld()));
		if (GM)
		{

			FullDialog = GM->GetMainDialogComponent()->GetAllDialogTopicForMetaBundle(ID);
		}
		/*else
		{
			AMainGameState* GS = Cast<AMainGameState>(UGameplayStatics::GetGameState(WorldContext));
			check(GS);
			if (GS)
				LocalItem = GS->FetchItemFromID(ItemID);
		}*/

	for(auto & DialogData : FullDialog)
	{
		DialogTopic.FindOrAdd(DialogData.Id,DialogData);
	}
}

const FDialogTopicStruct& UDialogComponent::GetDialogTopic(int64 ID) const
{
	return DialogTopic[ID];
}
