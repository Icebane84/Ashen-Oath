// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSigilResonanceEvaluator.h"
#include "Combat/AshenRunicForgeBalanceDataAsset.h"

bool UAshenSigilResonanceEvaluator::EvaluateHybridFinisher(
	EGuardSigilSocket StanceA,
	EGuardSigilSocket StanceB,
	const FSomaticState& SomaticState,
	float CompanionDistance,
	const UAshenRunicForgeBalanceDataAsset* BalanceData,
	FHybridFinisherPayload& OutPayload) const
{
	if (!BalanceData)
	{
		return false;
	}

	// Strict Spatial & Relational Gating (No Teleportation: must be in close combat pocket <= 200uu)
	if (CompanionDistance > BalanceData->FlowGlintMaxProximityRadius ||
		SomaticState.RelationalFlow < 0.75f ||
		SomaticState.IsolationPressure > 0.40f)
	{
		return false;
	}

	// Vom Tag + Pflug: Cataclysm Vortex
	if ((StanceA == EGuardSigilSocket::VomTag && StanceB == EGuardSigilSocket::Pflug) ||
		(StanceA == EGuardSigilSocket::Pflug && StanceB == EGuardSigilSocket::VomTag))
	{
		OutPayload.FinisherTag = FGameplayTag::RequestGameplayTag(FName("Ability.Finisher.CataclysmVortex"));
		OutPayload.PoiseBreakMultiplier = 1.40f;
		OutPayload.DebtPurgeDelta = -0.15f;
		return true;
	}

	// Ochs + Mordhau: Sovereign Smite
	if ((StanceA == EGuardSigilSocket::Ochs && StanceB == EGuardSigilSocket::Mordhau) ||
		(StanceA == EGuardSigilSocket::Mordhau && StanceB == EGuardSigilSocket::Ochs))
	{
		OutPayload.FinisherTag = FGameplayTag::RequestGameplayTag(FName("Ability.Finisher.SovereignSmite"));
		OutPayload.PoiseBreakMultiplier = 2.00f;
		OutPayload.DebtPurgeDelta = -0.10f;
		return true;
	}

	return false;
}

bool UAshenSigilResonanceEvaluator::CanTriggerResonance(
	ESigilResonanceEffect SigilA,
	ESigilResonanceEffect SigilB) const
{
	return (SigilA != ESigilResonanceEffect::None && SigilB != ESigilResonanceEffect::None);
}

float UAshenSigilResonanceEvaluator::EvaluateHybridFinisherDamage(
	ESigilResonanceEffect SigilA,
	ESigilResonanceEffect SigilB) const
{
	if (CanTriggerResonance(SigilA, SigilB))
	{
		return 1.40f;
	}

	return 1.00f;
}
