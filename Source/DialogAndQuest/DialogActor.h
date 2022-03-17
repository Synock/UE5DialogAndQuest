// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DialogInterface.h"
#include "DialogActor.generated.h"

UCLASS()
class DIALOGANDQUEST_API ADialogActor : public AActor, public IDialogInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADialogActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	float BP_GetRelation() const;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	FString BP_GetRelationString(float Relation) const;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	UDialogComponent* BP_GetDialogComponent() const;

	UPROPERTY(Replicated, BlueprintReadWrite)
	TObjectPtr<UDialogComponent> Dialog;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float GetRelation() const override;

	virtual UDialogComponent* GetDialogComponent() const override;

	virtual FString GetRelationString(float Relation) const override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
