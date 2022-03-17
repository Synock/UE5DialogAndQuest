// Copyright 2022 Maximilien (Synock) Guislain


#include "DialogActor.h"

#include "Net/UnrealNetwork.h"


// Sets default values
ADialogActor::ADialogActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	//bAlwaysRelevant = true;
	if (HasAuthority())
	{
		Dialog = CreateDefaultSubobject<UDialogComponent>("DialogComponent");
		Dialog->SetNetAddressable(); // Make DSO components net addressable
		Dialog->SetIsReplicated(true); // Enable replication by default
	}
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
	return Dialog;
}

FString ADialogActor::GetRelationString(float Relation) const
{
	return BP_GetRelationString(Relation);
}

//----------------------------------------------------------------------------------------------------------------------

void ADialogActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// Here we list the variables we want to replicate + a condition if wanted
	DOREPLIFETIME(ADialogActor, Dialog);
}
