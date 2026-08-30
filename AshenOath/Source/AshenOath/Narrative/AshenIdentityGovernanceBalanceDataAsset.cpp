// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenIdentityGovernanceBalanceDataAsset.h"

FIdentityGovernanceLimits UAshenIdentityGovernanceBalanceDataAsset::GetClampedLimits() const
{
	FIdentityGovernanceLimits Clamped = GovernanceLimits;
	Clamped.MaxAllowableDelta = FMath::Clamp(Clamped.MaxAllowableDelta, 0.05f, 0.50f);
	Clamped.MaxJsonPayloadSizeKB = FMath::Clamp(Clamped.MaxJsonPayloadSizeKB, 1, 16);
	return Clamped;
}

FMemoryDecayBalancing UAshenIdentityGovernanceBalanceDataAsset::GetClampedDecay() const
{
	FMemoryDecayBalancing Clamped = DecayBalancing;
	Clamped.TraumaDecayLambda = FMath::Clamp(Clamped.TraumaDecayLambda, 0.001f, 0.10f);
	Clamped.BondDecayLambda = FMath::Clamp(Clamped.BondDecayLambda, 0.01f, 0.25f);
	Clamped.EpiphanyDecayLambda = FMath::Clamp(Clamped.EpiphanyDecayLambda, 0.005f, 0.15f);
	Clamped.CombatTitheDecayLambda = FMath::Clamp(Clamped.CombatTitheDecayLambda, 0.02f, 0.35f);
	Clamped.ActiveSalienceThreshold = FMath::Clamp(Clamped.ActiveSalienceThreshold, 0.05f, 0.50f);
	return Clamped;
}

float UAshenIdentityGovernanceBalanceDataAsset::GetLambdaForCategory(EImprintSalienceCategory Category) const
{
	FMemoryDecayBalancing Decay = GetClampedDecay();
	switch (Category)
	{
	case EImprintSalienceCategory::Trauma:
		return Decay.TraumaDecayLambda;
	case EImprintSalienceCategory::CompanionBond:
		return Decay.BondDecayLambda;
	case EImprintSalienceCategory::HistoricalEpiphany:
		return Decay.EpiphanyDecayLambda;
	case EImprintSalienceCategory::CombatTithe:
		return Decay.CombatTitheDecayLambda;
	default:
		return Decay.TraumaDecayLambda;
	}
}
