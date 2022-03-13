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
	TMap<FString, int64> DialogTopicLUT;

	UPROPERTY(BlueprintReadWrite)
	FString DialogName;

	UPROPERTY(BlueprintReadWrite)
	FString GoodGreeting;

	UPROPERTY(BlueprintReadWrite)
	FString BadGreeting;

	UPROPERTY(BlueprintReadWrite)
	float GreetingLimit = 0.f;


public:

	UFUNCTION(BlueprintCallable)
	void InitDialogFromID(int64 ID);

	UFUNCTION(BlueprintCallable)
	const FDialogTopicStruct& GetDialogTopic(int64 ID) const;

	UFUNCTION(BlueprintCallable)
	int64 GetDialogTopicID(const FString& ID) const;

	UFUNCTION(BlueprintCallable)
	FString ParseTextHyperlink(const FString& OriginalString, const AActor* DialogActor) const;

	UFUNCTION(BlueprintCallable)
	const FString & GetGoodGreeting() const {return GoodGreeting;}

	UFUNCTION(BlueprintCallable)
	const FString & GetBadGreeting() const {return BadGreeting;}

	UFUNCTION(BlueprintCallable)
	float GetGreetingLimit() const {return GreetingLimit;}
};
