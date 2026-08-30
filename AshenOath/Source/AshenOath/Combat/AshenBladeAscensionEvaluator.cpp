// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenBladeAscensionEvaluator.h"
#include "Combat/AshenRunicForgeBalanceDataAsset.h"

EOathbringerAscensionTier UAshenBladeAscensionEvaluator::EvaluateAscensionTier(
	const FSoulStateVector& CanonicalSoul,
	const FRelationalMatrix_V2& RelationalMatrix,
	const UAshenRunicForgeBalanceDataAsset* BalanceData) const
{
	if (!BalanceData)
	{
		return EOathbringerAscensionTier::Tier1_DullNightsteel;
	}

	// Tier 5: Zenith Sovereign (Symbiotic Equilibrium: Resolve >= 0.90, Debt == 0.0)
	if (CanonicalSoul.Resolve >= BalanceData->Tier5ResolveThreshold &&
		CanonicalSoul.IntegrationDebt <= KINDA_SMALL_NUMBER)
	{
		return EOathbringerAscensionTier::Tier5_GodslayerApex;
	}

	// Tier 4: Eldrin's Crucible (Bifurcated Will: Corruption >= 0.50, Resolve >= 0.70)
	if (CanonicalSoul.Corruption >= BalanceData->Tier4CorruptionThreshold &&
		CanonicalSoul.Resolve >= BalanceData->Tier4ResolveThreshold)
	{
		return EOathbringerAscensionTier::Tier4_EldrinsCrucible;
	}

	// Tier 3: Sundered Sovereign (Relational Synchronization Matrix Predicate)
	if (RelationalMatrix.IsEligibleForRelationalFinisher() &&
		RelationalMatrix.TrioResonance >= BalanceData->Tier3TrioResonanceThreshold)
	{
		return EOathbringerAscensionTier::Tier3_SunderedSovereign;
	}

	// Tier 2: The Resonant Fuller (Integration Debt Fracturing Steel: Debt >= 0.25)
	if (CanonicalSoul.IntegrationDebt >= BalanceData->Tier2DebtThreshold)
	{
		return EOathbringerAscensionTier::Tier2_AwakenedFuller;
	}

	// Tier 1: The Burdened Iron (Dormant Baseline)
	return EOathbringerAscensionTier::Tier1_DullNightsteel;
}

bool UAshenBladeAscensionEvaluator::IsEligibleForAscension(
	EOathbringerAscensionTier CurrentTier,
	int32 BossKills,
	int32 HearthsLit,
	int32 ForensicCases) const
{
	switch (CurrentTier)
	{
	case EOathbringerAscensionTier::Tier1_DullNightsteel:
		return (BossKills >= 1 && HearthsLit >= 1);

	case EOathbringerAscensionTier::Tier2_AwakenedFuller:
		return (BossKills >= 2 && HearthsLit >= 3 && ForensicCases >= 1);

	case EOathbringerAscensionTier::Tier3_SunderedSovereign:
		return (BossKills >= 3 && HearthsLit >= 4 && ForensicCases >= 2);

	case EOathbringerAscensionTier::Tier4_EldrinsCrucible:
		return (BossKills >= 4 && HearthsLit >= 5 && ForensicCases >= 3);

	case EOathbringerAscensionTier::Tier5_GodslayerApex:
	default:
		return false;
	}
}
