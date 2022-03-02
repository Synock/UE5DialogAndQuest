// Copyright 2022 Maximilien (Synock) Guislain


#include "UI/RichInlineHyperlinkDecorator.h"

#include "Framework/Text/SlateHyperlinkRun.h"
#include "Widgets/Input/SRichTextHyperlink.h"

class DIALOGANDQUESTPLUGIN_API FRichInlineHyperlinkDecorator : public FRichTextDecorator
{
public:
	FRichInlineHyperlinkDecorator(URichTextBlock* InOwner, class URichInlineHyperlinkDecorator* Decorator);
	virtual bool Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const override;
protected:
	virtual TSharedPtr<SWidget> CreateDecoratorWidget(const FTextRunInfo& RunInfo,
													  const FTextBlockStyle& TextStyle) const override;
	FHyperlinkStyle LinkStyle;
	FSimpleDelegate Delegate;
	mutable FString IDString;
};

URichInlineHyperlinkDecorator::URichInlineHyperlinkDecorator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FRichInlineHyperlinkDecorator::FRichInlineHyperlinkDecorator(URichTextBlock* InOwner,
                                                             URichInlineHyperlinkDecorator* Decorator)
	: FRichTextDecorator(InOwner)
{
	LinkStyle = Decorator->Style;
	Delegate.BindLambda([=]()
	{
		Decorator->ClickFun();
	});
}

bool FRichInlineHyperlinkDecorator::Supports(const FTextRunParseResults& RunParseResult, const FString& Text) const

{
	if (RunParseResult.Name == TEXT("a") && RunParseResult.MetaData.Contains(TEXT("id")))
	{
		const FTextRange& IdRange = RunParseResult.MetaData[TEXT("id")];
		IDString = Text.Mid(IdRange.BeginIndex, IdRange.EndIndex - IdRange.BeginIndex);
		return true;
	}
	return false;
}

TSharedPtr<SWidget> FRichInlineHyperlinkDecorator::CreateDecoratorWidget(
	const FTextRunInfo& RunInfo, const FTextBlockStyle& TextStyle) const
{
	const bool bWarnIfMissing = true;

	TSharedPtr<FSlateHyperlinkRun::FWidgetViewModel> model = MakeShareable(new FSlateHyperlinkRun::FWidgetViewModel);

	TSharedPtr<SRichTextHyperlink> link = SNew(SRichTextHyperlink, model.ToSharedRef())
		.Text(FText::FromString("link"))
		.Style(&LinkStyle)
		.OnNavigate(Delegate);

	return link;
}

//////////////////////////////////////////////////////////////////////////

TSharedPtr<ITextDecorator> URichInlineHyperlinkDecorator::CreateDecorator(URichTextBlock* InOwner)
{
	return MakeShareable(new FRichInlineHyperlinkDecorator(InOwner, this));
}

void URichInlineHyperlinkDecorator::ClickFun_Implementation()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Red, "click link");
	}
}
