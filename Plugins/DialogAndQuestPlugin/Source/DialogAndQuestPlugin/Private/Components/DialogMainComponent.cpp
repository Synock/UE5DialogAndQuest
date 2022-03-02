// Copyright 2022 Maximilien (Synock) Guislain


#include "Components/DialogMainComponent.h"


// Sets default values for this component's properties
UDialogMainComponent::UDialogMainComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UDialogMainComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

void UDialogMainComponent::AddTopic(const FDialogTopicStruct& NewTopic)
{
	DialogTopic.Add(NewTopic.Id, NewTopic);
	DialogTopicLUT.Add(NewTopic.Topic, NewTopic.Id);
}

void UDialogMainComponent::AddBundle(const FDialogTopicBundleStruct& Bundle)
{
	DialogBundle.Add(Bundle.Id ,Bundle);
}

void UDialogMainComponent::AddMetaBundle(const FDialogTopicMetaBundleStruct& MetaBundle)
{
	DialogMetaBundle.Add(MetaBundle.Id, MetaBundle);
}
