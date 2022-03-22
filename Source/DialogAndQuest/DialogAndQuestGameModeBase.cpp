// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogAndQuestGameModeBase.h"

#include "Dialog/DialogData.h"

void ADialogAndQuestGameModeBase::BeginPlay()
{
	Super::BeginPlay();


	FDialogTopicStruct Topic1;
	Topic1.Id = 1;
	Topic1.Topic = "Lorem";
	Topic1.TopicText =
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc a pretium nisl, vitae mattis nisl."
		"Curabitur euismod lectus maximus mi dapibus, ac vestibulum sem scelerisque. "
		"Ut ac ipsum ornare, accumsan tellus sed, consectetur erat. In blandit elementum hendrerit. "
		"Aliquam elementum eros in metus viverra, et volutpat tortor pretium. Praesent eget nibh at purus egestas euismod. "
		"Nunc in pharetra augue. Fusce blandit facilisis augue, a luctus risus tempor nec. "
		"Sed eget nibh sodales, eleifend neque eget, mollis orci."
		" Mauris lobortis lacus vitae nulla pellentesque tempor a id risus. "
		" Curabitur lobortis neque quis diam lacinia, ac consequat quam mattis."
		" Nulla pulvinar neque quis lacus vestibulum sollicitudin a eget dui. Nulla interdum ullamcorper mauris eu ultrices."
		" Duis efficitur mollis purus vel pharetra. In orci purus, pulvinar sed dui et, iaculis facilisis quam.";


	DialogComponent->AddTopic(Topic1);

	FDialogTopicStruct Topic2;
	Topic2.Id = 2;
	Topic2.Topic = "Nunc";
	Topic2.TopicText =
		"Nunc in magna vestibulum, ultricies libero at, egestas felis. Integer vel enim eget magna molestie tempor auctor quis nunc. Vivamus euismod finibus ornare. Nulla facilisi. Nam tincidunt varius erat. Donec bibendum in neque vulputate lobortis. Nullam leo orci, bibendum et nunc eget, aliquam faucibus quam. Quisque vestibulum neque nec sagittis blandit. Donec ac tortor euismod nibh rutrum pretium non eget orci. Pellentesque a elementum magna. Aenean ut tristique mi. Aliquam in faucibus nisi. Pellentesque a urna urna.";

	DialogComponent->AddTopic(Topic2);

	FDialogTopicStruct Topic3;
	Topic3.Id = 3;
	Topic3.Topic = "Nulla";
	Topic3.TopicText ="Nulla iaculis posuere ex, rutrum tempor erat imperdiet non. Pellentesque vel risus ac orci placerat sollicitudin. Ut faucibus nibh elit, pharetra tempus nisi lobortis non. Vivamus at lacus ligula. Nulla facilisi. Donec a ornare tellus. Aenean sollicitudin placerat interdum. Etiam laoreet dolor sed diam ultrices sollicitudin. Proin tincidunt sodales magna sed maximus. Vestibulum mattis ornare purus non suscipit. Phasellus vehicula vehicula pretium. Fusce sed diam nec tortor tristique suscipit. Nunc dignissim porttitor elit in convallis. Phasellus maximus volutpat justo, ut vestibulum turpis varius sagittis. ";
	DialogComponent->AddTopic(Topic3);

	FDialogTopicStruct Topic4;
	Topic4.Id = 4;
	Topic4.Topic = "Maecenas";
	Topic4.TopicText ="Maecenas lacinia metus sed nulla cursus, eu scelerisque metus facilisis. Nullam venenatis elit id purus rutrum convallis. Nulla eu accumsan magna, a porta sem. Praesent non egestas arcu. Aliquam luctus vitae ante ut ornare. Suspendisse at faucibus eros. Sed ac nisl aliquet, ornare lorem quis, sollicitudin nunc. Proin sodales purus sed mauris semper, eget hendrerit nisl pulvinar. Pellentesque non leo arcu. Sed sodales iaculis diam, quis mollis sapien tincidunt in. Morbi scelerisque nibh at enim condimentum congue at at risus. Suspendisse non tellus eget turpis eleifend lobortis vitae a odio. Mauris suscipit placerat leo. Cras sem dolor, volutpat ac nisi at, facilisis volutpat ante. Donec nibh neque, bibendum pretium libero ac, congue vehicula metus. ";
	DialogComponent->AddTopic(Topic4);

	FDialogTopicStruct Topic5;
	Topic5.Id = 5;
	Topic5.Topic = "Praesent";
	Topic5.TopicText ="Praesent rhoncus porta elit, a interdum arcu lacinia nec. Fusce placerat, neque in scelerisque faucibus, sapien ex feugiat turpis, vitae dignissim purus arcu eget metus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nam vehicula tempus rutrum. Maecenas rutrum ullamcorper aliquet. Etiam id odio lacus. Sed non mi sit amet erat bibendum mollis ut ac justo. ";
	DialogComponent->AddTopic(Topic5);

	FDialogTopicStruct TopicSecret;
	TopicSecret.Id = 6;
	TopicSecret.TopicCondition.MinimumRelation = 0.65;
	TopicSecret.Topic = "Secret";
	TopicSecret.TopicText = "You can only read this secret topic because I like you";
	DialogComponent->AddTopic(TopicSecret);

	FDialogTopicBundleStruct Bundle;
	Bundle.Id = 1;
	Bundle.MetaName = "TestBundle";
	Bundle.TopicList = {1,2,3,4,5,6};

	FDialogTopicMetaBundleStruct MetaBundle;
	MetaBundle.Id = 1;
	MetaBundle.MetaName = "TestBundle";
	MetaBundle.TopicBundleList = {1};

	DialogComponent->AddBundle(Bundle);
	DialogComponent->AddMetaBundle(MetaBundle);




	{
		FQuestMetaData QuestData1;
		QuestData1.Repeatable = false;
		QuestData1.QuestTitle = "Test Quest 1";
		QuestData1.QuestID = 1;

		FQuestStep Step1;
		Step1.StepTitle = "Find QuestGiver 2";
		Step1.StepDescription = "I am supposed to find QuestGiver2 and talk to him, or something.";
		Step1.QuestSubID = 0;
		QuestData1.Steps.Add(Step1);

		FQuestStep Step2;
		Step2.StepTitle = "Find QuestGiver 1, again";
		Step2.StepDescription = "I am supposed to go back to QuestGiver 1 and talk to him, again.";
		Step2.QuestSubID = 10;
		QuestData1.Steps.Add(Step2);

		FQuestStep Step3;
		Step3.StepTitle = "Quest Finished";
		Step3.StepDescription = "This quest is now finished or something";
		Step3.QuestSubID = 20;
		QuestData1.Steps.Add(Step3);

		QuestComponent->AddQuest(QuestData1);

		FDialogTopicStruct TopicQuest1;
		TopicQuest1.Id = 7;
		TopicQuest1.TopicCondition.MinimumRelation = 0.5;
		TopicQuest1.Topic = "Quest1";
		TopicQuest1.TopicText = "Yes yes, go talk to QuestGiver2 or something";
		TopicQuest1.QuestRelation.QuestID = 1;
		TopicQuest1.QuestRelation.Steps.Add(0);
		TopicQuest1.QuestRelation.Steps.Add(20);
		DialogComponent->AddTopic(TopicQuest1);

		FDialogTopicStruct TopicQuest2;
		TopicQuest2.Id = 8;
		TopicQuest2.TopicCondition.MinimumRelation = 0.5;
		TopicQuest2.Topic = "Quest 1 Step 2";
		TopicQuest2.TopicText = "Ah yes, please tell QuestGiver1 to eat a bag of chips";
		TopicQuest2.QuestRelation.QuestID = 1;
		TopicQuest2.QuestRelation.Steps.Add(10);

		FDialogTopicCondition Cond;
		Cond.QuestId = 1;
		Cond.MinimumStepID = 0;
		TopicQuest2.TopicCondition = Cond;
		DialogComponent->AddTopic(TopicQuest2);

		FDialogTopicBundleStruct Bundle2;
		Bundle2.Id = 2;
		Bundle2.MetaName = "TestBundle";
		Bundle2.TopicList = {7};

		FDialogTopicBundleStruct Bundle3;
		Bundle3.Id = 3;
		Bundle3.MetaName = "TestBundle2";
		Bundle3.TopicList = {8};

		FDialogTopicMetaBundleStruct MetaBundleQuest1;
		MetaBundleQuest1.Id = 2;
		MetaBundleQuest1.MetaName = "QuestBundle1";
		MetaBundleQuest1.TopicBundleList = {1, 2};

		FDialogTopicMetaBundleStruct MetaBundleQuest2;
		MetaBundleQuest2.Id = 3;
		MetaBundleQuest2.MetaName = "QuestBundle2";
		MetaBundleQuest2.TopicBundleList = {1, 3};

		DialogComponent->AddBundle(Bundle2);
		DialogComponent->AddMetaBundle(MetaBundleQuest1);
		DialogComponent->AddBundle(Bundle3);
		DialogComponent->AddMetaBundle(MetaBundleQuest2);
	}



	{
		FQuestMetaData QuestData2;
		QuestData2.Repeatable = false;
		QuestData2.QuestTitle = "Journey Quest";
		QuestData2.QuestID = 2;

		FQuestStep Step1;
		Step1.StepTitle = "Explore High Mountains";
		Step1.StepDescription = "I am supposed to climb a high mountain, sort of.";
		Step1.QuestSubID = 0;
		QuestData2.Steps.Add(Step1);

		FQuestStep Step2;
		Step2.StepTitle = "Explore Deep Caves";
		Step2.StepDescription = "I am supposed to explore a deep cave.";
		Step2.QuestSubID = 10;
		QuestData2.Steps.Add(Step2);

		FQuestStep Step3;
		Step3.StepTitle = "Explore Great Flat";
		Step3.StepDescription = "What is this now, a running simulator?";
		Step3.QuestSubID = 20;
		QuestData2.Steps.Add(Step3);

		QuestComponent->AddQuest(QuestData2);
	}


}

ADialogAndQuestGameModeBase::ADialogAndQuestGameModeBase()
{
	if (HasAuthority())
	{
		DialogComponent = CreateDefaultSubobject<UDialogMainComponent>("DialogMainComponent");
		//DialogComponent->SetNetAddressable();
		//DialogComponent->SetIsReplicated(true);

		QuestComponent = CreateDefaultSubobject<UQuestMainComponent>("QuestMainComponent");
	}
}
