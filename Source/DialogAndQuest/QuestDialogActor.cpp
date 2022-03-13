// Copyright 2022 Maximilien (Synock) Guislain


#include "QuestDialogActor.h"


// Sets default values
AQuestDialogActor::AQuestDialogActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuestDialogActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestDialogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

