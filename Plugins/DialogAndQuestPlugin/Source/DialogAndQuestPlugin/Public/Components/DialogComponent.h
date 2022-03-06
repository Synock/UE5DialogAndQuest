// Copyright 2022 Maximilien (Synock) Guislain

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Dialog/DialogData.h"
#include "DialogComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DIALOGANDQUESTPLUGIN_API UDialogComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDialogComponent();

	FString GetDialogName() const {return DialogName;}

	TArray<FDialogTopicStruct> GetAllDialogTopic() const;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	TMap<int64, FDialogTopicStruct> DialogTopic;

	UPROPERTY(BlueprintReadWrite)
	FString DialogName;

public:

	UFUNCTION(BlueprintCallable)
	void InitDialogFromID(int64 ID);

	UFUNCTION(BlueprintCallable)
	const FDialogTopicStruct& GetDialogTopic(int64 ID) const;
};