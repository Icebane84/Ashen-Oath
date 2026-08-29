// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenMemoryPalaceSynthesisEvaluator.h"

UAshenMemoryPalaceSynthesisEvaluator::UAshenMemoryPalaceSynthesisEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

float UAshenMemoryPalaceSynthesisEvaluator::EvaluateSynthesisScore(
	int32 PinnedCluesCount,
	float AverageReliability) const
{
	float BaseMultiplier = 0.35f;
	if (BalanceDataAsset)
	{
		BaseMultiplier = BalanceDataAsset->GetClampedDeduction().ClueBaseWeightMultiplier;
	}

	const float BaseScore = static_cast<float>(PinnedCluesCount) * BaseMultiplier;
	return FMath::Clamp(BaseScore * AverageReliability, 0.0f, 1.0f);
}

bool UAshenMemoryPalaceSynthesisEvaluator::IsCaseResolvable(
	float SynthesisScore) const
{
	float Threshold = 0.85f;
	if (BalanceDataAsset)
	{
		Threshold = BalanceDataAsset->GetClampedDeduction().ResolutionSynthesisThreshold;
	}

	return SynthesisScore >= Threshold;
}

bool UAshenMemoryPalaceSynthesisEvaluator::DetectContradiction(
	EForensicClueCategory ClueA,
	EForensicClueCategory ClueB) const
{
	// Physical autopsy fact directly contradicts subjective companion dogma
	return (ClueA == EForensicClueCategory::PhysicalAutopsyEvidence && ClueB == EForensicClueCategory::CompanionTestimony) ||
	       (ClueA == EForensicClueCategory::CompanionTestimony && ClueB == EForensicClueCategory::PhysicalAutopsyEvidence);
}
