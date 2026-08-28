// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_BladeSanityConductorHUD.h"

UAshenUserWidget_BladeSanityConductorHUD::UAshenUserWidget_BladeSanityConductorHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedHarmonics.BladeHunger01 = 0.0f;
	DisplayedHarmonics.HungerStage = EBladeHungerStage::SatedDormant;
	DisplayedHarmonics.CurrentSanity = 100.0f;
	DisplayedHarmonics.DissonanceTier = ESanityDissonanceTier::LucidHarmonic;
	DisplayedHarmonics.Stem02WhisperGain = 0.0f;
	DisplayedHarmonics.MelodicDuckingDb = 0.0f;
	DisplayedHarmonics.bFlowStateActive = false;
}

void UAshenUserWidget_BladeSanityConductorHUD::UpdateConvergenceHUD(
	const FBladeSanityHarmonicVector& Harmonics)
{
	DisplayedHarmonics = Harmonics;
}
