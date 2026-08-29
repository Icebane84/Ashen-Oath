// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenAdrenalineSurgeEvaluator.h"

UAshenAdrenalineSurgeEvaluator::UAshenAdrenalineSurgeEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

float UAshenAdrenalineSurgeEvaluator::EvaluateAdrenalineGain(
	ESeveranceSeverityTier Severity) const
{
	float DecapAdrenaline = 35.0f;
	float BisectionAdrenaline = 40.0f;
	float MajorLimbAdrenaline = 25.0f;

	if (BalanceDataAsset)
	{
		FAdrenalineSurgeBalancing Adrenaline = BalanceDataAsset->GetClampedAdrenaline();
		DecapAdrenaline = Adrenaline.DecapitationAdrenaline;
		BisectionAdrenaline = Adrenaline.BisectionAdrenaline;
		MajorLimbAdrenaline = Adrenaline.MajorLimbAdrenaline;
	}

	switch (Severity)
	{
	case ESeveranceSeverityTier::Decapitation:
		return DecapAdrenaline;
	case ESeveranceSeverityTier::TotalBisection:
		return BisectionAdrenaline;
	case ESeveranceSeverityTier::MajorLimb:
		return MajorLimbAdrenaline;
	case ESeveranceSeverityTier::MinorLimb:
	default:
		return 15.0f;
	}
}

float UAshenAdrenalineSurgeEvaluator::EvaluateStaminaRefill(
	float CurrentAdrenaline) const
{
	float RefillScalar = 0.50f;
	if (BalanceDataAsset)
	{
		RefillScalar = BalanceDataAsset->GetClampedAdrenaline().StaminaRefillScalar;
	}

	return FMath::Clamp(CurrentAdrenaline * RefillScalar, 15.0f, 50.0f);
}
