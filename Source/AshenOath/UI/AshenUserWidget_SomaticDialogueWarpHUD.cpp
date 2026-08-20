// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_SomaticDialogueWarpHUD.h"

UAshenUserWidget_SomaticDialogueWarpHUD::UAshenUserWidget_SomaticDialogueWarpHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurrentCorruptionIntensity = 0.0f;
	CurrentSqueezeRatio = 0.0f;
	VioletInkColor = FLinearColor(0.45f, 0.05f, 0.75f, 1.0f);
}

void UAshenUserWidget_SomaticDialogueWarpHUD::UpdateDialogueCorruption(float ParasitePressure, float InternalFriction)
{
	CurrentCorruptionIntensity = FMath::Clamp((ParasitePressure * 0.60f) + (InternalFriction * 0.40f), 0.0f, 1.0f);
}

void UAshenUserWidget_SomaticDialogueWarpHUD::SetDialogueTexts(const FText& InTrueText, const FText& InParasiticOverwrite)
{
	TrueText = InTrueText;
	ParasiticOverwritingText = InParasiticOverwrite;
}

void UAshenUserWidget_SomaticDialogueWarpHUD::UpdateSqueezeProgress(float CompletionRatio)
{
	CurrentSqueezeRatio = FMath::Clamp(CompletionRatio, 0.0f, 1.0f);
}
