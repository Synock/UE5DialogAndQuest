// Copyright 2022 Maximilien (Synock) Guislain


#include "DialogActor.h"


// Sets default values
ADialogActor::ADialogActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADialogActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADialogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ADialogActor::GetRelation() const
{
	return BP_GetRelation();
}

UDialogComponent* ADialogActor::GetDialogComponent() const
{
	return BP_GetDialogComponent();
}

FString ADialogActor::GetRelationString(float Relation) const
{
	return BP_GetRelationString(Relation);
}

