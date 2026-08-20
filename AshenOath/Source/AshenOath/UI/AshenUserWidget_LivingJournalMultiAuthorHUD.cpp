// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_LivingJournalMultiAuthorHUD.h"

UAshenUserWidget_LivingJournalMultiAuthorHUD::UAshenUserWidget_LivingJournalMultiAuthorHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentSootIntensity = 0.0f;
}

void UAshenUserWidget_LivingJournalMultiAuthorHUD::DisplayJournalSpread(
	const FText& InKaelenText,
	const FText& InGarrettMarginNote,
	const FText& InSerafinaReflection,
	float SootStainIntensity)
{
	KaelenProse = InKaelenText;
	GarrettDiagramText = InGarrettMarginNote;
	SerafinaReflectionText = InSerafinaReflection;
	CurrentSootIntensity = FMath::Clamp(SootStainIntensity, 0.0f, 1.0f);
}

void UAshenUserWidget_LivingJournalMultiAuthorHUD::SetAuthorLayerOpacity(EAuthorIdentity Author, float Opacity)
{
}
