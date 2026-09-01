// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/SAshenCampfireConstellationWidget.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SBoxPanel.h"

void SAshenCampfireConstellationWidget::Construct(const FArguments& InArgs)
{
	OnLensSelectedDelegate = InArgs._OnLensSelected;

	ChildSlot
	[
		SNew(SBorder)
		.BorderBackgroundColor(FLinearColor(0.02f, 0.02f, 0.03f, 0.90f))
		.Padding(FMargin(24.0f))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(0.0f, 0.0f, 0.0f, 16.0f))
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("CAMPFIRE REFLECTION & SOUL CONSTELLATION")))
				.Font(FCoreStyle::GetDefaultFontStyle("Bold", 18))
				.ColorAndOpacity(FLinearColor(0.9f, 0.85f, 0.75f, 1.0f))
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(0.0f, 0.0f, 0.0f, 16.0f))
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SButton)
					.OnClicked_Lambda([this]() { return HandleLensButtonClicked(EInterpretiveLens::Accountability); })
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("1. Accountability (+Resolve)")))
					]
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(FMargin(8.0f, 0.0f, 0.0f, 0.0f))
				[
					SNew(SButton)
					.OnClicked_Lambda([this]() { return HandleLensButtonClicked(EInterpretiveLens::Grace); })
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("2. Grace / Compassion (+Trust)")))
					]
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(FMargin(8.0f, 0.0f, 0.0f, 0.0f))
				[
					SNew(SButton)
					.OnClicked_Lambda([this]() { return HandleLensButtonClicked(EInterpretiveLens::Nihilism); })
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("3. Nihilism (+Corruption)")))
					]
				]
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.Padding(FMargin(8.0f, 0.0f, 0.0f, 0.0f))
				[
					SNew(SButton)
					.OnClicked_Lambda([this]() { return HandleLensButtonClicked(EInterpretiveLens::Penance); })
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("4. Penance (+Poise Floor)")))
					]
				]
			]
		]
	];
}

void SAshenCampfireConstellationWidget::UpdateSoulTelemetry(
	float InResolve,
	float InCorruption,
	float InDebt,
	EOathbringerMetallurgicalTier InTier)
{
	CachedResolve = InResolve;
	CachedCorruption = InCorruption;
	CachedDebt = InDebt;
	CachedTier = InTier;
}

void SAshenCampfireConstellationWidget::SetSelectedLens(EInterpretiveLens NewLens)
{
	CurrentLens = NewLens;
}

FReply SAshenCampfireConstellationWidget::HandleLensButtonClicked(EInterpretiveLens InLens)
{
	CurrentLens = InLens;
	if (OnLensSelectedDelegate.IsBound())
	{
		OnLensSelectedDelegate.Execute(CurrentLens);
	}
	return FReply::Handled();
}
