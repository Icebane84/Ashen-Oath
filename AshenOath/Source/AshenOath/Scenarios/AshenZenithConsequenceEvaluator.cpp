// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenZenithConsequenceEvaluator.h"

UAshenZenithConsequenceEvaluator::UAshenZenithConsequenceEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EZenithConsequenceEnding UAshenZenithConsequenceEvaluator::EvaluateConsequenceEnding(
	float TrustScore01,
	float IntegrationDebt01,
	bool bBerserkDominant) const
{
	if (IntegrationDebt01 >= 0.85f)
	{
		return EZenithConsequenceEnding::AshenEclipse;
	}

	if (TrustScore01 < 0.40f)
	{
		return EZenithConsequenceEnding::BleedingFracture;
	}

	if (bBerserkDominant || TrustScore01 < 0.75f)
	{
		return EZenithConsequenceEnding::CauterizedHegemony;
	}

	return EZenithConsequenceEnding::RadiantTransfiguration;
}

ETripartiteAlignmentTier UAshenZenithConsequenceEvaluator::EvaluateAlignmentTier(float TrustScore01) const
{
	if (TrustScore01 < 0.40f)
	{
		return ETripartiteAlignmentTier::FracturedDiscord;
	}
	if (TrustScore01 <= 0.75f)
	{
		return ETripartiteAlignmentTier::TemperedAlliance;
	}
	return ETripartiteAlignmentTier::SovereignTriad;
}
