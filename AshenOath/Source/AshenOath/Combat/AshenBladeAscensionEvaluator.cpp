// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenBladeAscensionEvaluator.h"

UAshenBladeAscensionEvaluator::UAshenBladeAscensionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenBladeAscensionEvaluator::IsEligibleForAscension(
	EOathbringerAscensionTier CurrentTier,
	int32 DefeatedSanctumBosses,
	int32 IgnitedHearthstones,
	int32 SolvedForensicCases) const
{
	switch (CurrentTier)
	{
	case EOathbringerAscensionTier::Tier1_DullNightsteel:
		// Requires 1 Sanctum Boss + 1 Hearthstone
		return (DefeatedSanctumBosses >= 1 && IgnitedHearthstones >= 1);

	case EOathbringerAscensionTier::Tier2_AwakenedFuller:
		// Requires 2 Bosses + 3 Hearthstones + 1 Forensic Case (Unlocks 4 sockets)
		return (DefeatedSanctumBosses >= 2 && IgnitedHearthstones >= 3 && SolvedForensicCases >= 1);

	case EOathbringerAscensionTier::Tier3_SunderedSovereign:
		// Requires 4 Bosses + 5 Hearthstones + 3 Cases (Eldrin's Crucible)
		return (DefeatedSanctumBosses >= 4 && IgnitedHearthstones >= 5 && SolvedForensicCases >= 3);

	case EOathbringerAscensionTier::Tier4_EldrinsCrucible:
		// Requires 6 Bosses + 8 Hearthstones + 5 Cases (Godslayer Apex)
		return (DefeatedSanctumBosses >= 6 && IgnitedHearthstones >= 8 && SolvedForensicCases >= 5);

	case EOathbringerAscensionTier::Tier5_GodslayerApex:
	default:
		return false; // Max tier achieved
	}
}
