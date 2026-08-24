// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenTraumaSomaticsSubsystem.h"

UAshenTraumaSomaticsSubsystem::UAshenTraumaSomaticsSubsystem()
{
	CurrentState.SomaticStage = ETraumaSomaticStage::Stage0_BaselinePristine;
	CurrentState.VeinCorruptionScalar = 0.0f;
	CurrentState.ScleraRednessScalar = 0.0f;
	CurrentState.SkinPallorScalar = 0.0f;
	CurrentState.HeartRateBPM = 60.0f;
	CurrentState.BladeSootScalar = 0.0f;
	CurrentState.BladeMicroNickCount = 0.0f;
}

void UAshenTraumaSomaticsSubsystem::UpdateSomaticState(
	float IntegrationDebt,
	float ShadowBurnout,
	float StrikeJoules,
	bool bInActiveCombat)
{
	// 1. Vein Corruption & Skin Pallor Math
	CurrentState.VeinCorruptionScalar = FMath::Clamp(IntegrationDebt * 1.15f + ShadowBurnout * 0.35f, 0.0f, 1.0f);
	CurrentState.SkinPallorScalar = FMath::Clamp(IntegrationDebt * 0.85f, 0.0f, 1.0f);
	CurrentState.ScleraRednessScalar = FMath::Clamp((IntegrationDebt - 0.30f) / 0.70f, 0.0f, 1.0f);

	// Determine Clinical Stage
	ETraumaSomaticStage NewStage = ETraumaSomaticStage::Stage0_BaselinePristine;
	if (CurrentState.VeinCorruptionScalar >= 0.75f)
	{
		NewStage = ETraumaSomaticStage::Stage3_ShatteredVessel;
	}
	else if (CurrentState.VeinCorruptionScalar >= 0.50f)
	{
		NewStage = ETraumaSomaticStage::Stage2_VascularCrisis;
	}
	else if (CurrentState.VeinCorruptionScalar >= 0.25f)
	{
		NewStage = ETraumaSomaticStage::Stage1_SubcutaneousTaint;
	}

	if (NewStage != CurrentState.SomaticStage)
	{
		CurrentState.SomaticStage = NewStage;
		OnSomaticStageChanged.Broadcast(NewStage, CurrentState.VeinCorruptionScalar);
	}

	// 2. Blade Soot Accumulation Math
	if (StrikeJoules > 0.0f)
	{
		const float AddedSoot = (StrikeJoules / 5000.0f) * 0.05f;
		CurrentState.BladeSootScalar = FMath::Clamp(CurrentState.BladeSootScalar + AddedSoot, 0.0f, 1.0f);
		CurrentState.BladeMicroNickCount += (StrikeJoules > 2500.0f) ? 1.0f : 0.0f;

		EBladeSootDecayProfile SootProfile = EBladeSootDecayProfile::CleanPolishedSteel;
		if (CurrentState.BladeSootScalar >= 0.80f)
		{
			SootProfile = EBladeSootDecayProfile::SuperheatedSlag;
		}
		else if (CurrentState.BladeSootScalar >= 0.50f)
		{
			SootProfile = EBladeSootDecayProfile::CharredBlackSteel;
		}
		else if (CurrentState.BladeSootScalar >= 0.15f)
		{
			SootProfile = EBladeSootDecayProfile::SmokedEdge;
		}

		OnBladeSootUpdated.Broadcast(CurrentState.BladeSootScalar, SootProfile);
	}

	// 3. Heart Rate BPM Calculation
	const float BaseBPM = bInActiveCombat ? 110.0f : 60.0f;
	const float StressMultiplier = CurrentState.VeinCorruptionScalar * 60.0f;
	CurrentState.HeartRateBPM = FMath::Clamp(BaseBPM + StressMultiplier, 60.0f, 170.0f);

	OnHeartRateShifted.Broadcast(CurrentState.HeartRateBPM);
}

void UAshenTraumaSomaticsSubsystem::CleanBladeAtCampfire()
{
	CurrentState.BladeSootScalar = 0.0f;
	OnBladeSootUpdated.Broadcast(0.0f, EBladeSootDecayProfile::CleanPolishedSteel);
	OnBladeCleanedAtCampfire.Broadcast(0.10f);
}
