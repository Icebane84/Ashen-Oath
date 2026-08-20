// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_WordlessResonanceHUD.h"

UAshenUserWidget_WordlessResonanceHUD::UAshenUserWidget_WordlessResonanceHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentSilenceType = ESomaticSilenceClassification::None;
	CurrentStability = 1.0f;
}

void UAshenUserWidget_WordlessResonanceHUD::UpdateSilencePresentation(
	ESomaticSilenceClassification Classification,
	float Confidence)
{
	CurrentSilenceType = Classification;

	if (Classification == ESomaticSilenceClassification::DestabilizingCrisis)
	{
		CurrentStability = FMath::Clamp(1.0f - (Confidence * 0.40f), 0.30f, 1.0f);
	}
	else
	{
		CurrentStability = 1.0f;
	}
}
