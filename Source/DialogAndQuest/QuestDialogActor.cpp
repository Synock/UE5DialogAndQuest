// Copyright 2022 Maximilien (Synock) Guislain


#include "QuestDialogActor.h"


// Sets default values
AQuestDialogActor::AQuestDialogActor() : ADialogActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (HasAuthority())
	{
		QuestComponent = CreateDefaultSubobject<UQuestGiverComponent>("QuestComponent");
		QuestComponent->SetIsReplicated(false); // Enable replication by default
	}
}

//----------------------------------------------------------------------------------------------------------------------

// Called when the game starts or when spawned
void AQuestDialogActor::BeginPlay()
{
	Super::BeginPlay();
}

//----------------------------------------------------------------------------------------------------------------------

// Called every frame
void AQuestDialogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//----------------------------------------------------------------------------------------------------------------------

UQuestGiverComponent* AQuestDialogActor::GetQuestGiverComponent() const
{
	return QuestComponent;
}
