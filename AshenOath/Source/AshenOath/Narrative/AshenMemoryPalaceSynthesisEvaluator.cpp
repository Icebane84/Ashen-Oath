// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenMemoryPalaceSynthesisEvaluator.h"

UAshenMemoryPalaceSynthesisEvaluator::UAshenMemoryPalaceSynthesisEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenMemoryPalaceSynthesisEvaluator::EvaluateSynthesisScore(
	int32 PinnedCluesCount,
	float AverageReliability) const
{
	// 3 valid clues with 1.0 reliability reaches ~1.0 synthesis
	const float BaseScore = static_cast<float>(PinnedCluesCount) * 0.35f;
	return FMath::Clamp(BaseScore * AverageReliability, 0.0f, 1.0f);
}

bool UAshenMemoryPalaceSynthesisEvaluator::IsCaseResolvable(
	float SynthesisScore) const
{
	return SynthesisScore >= 0.85f;
}

bool UAshenMemoryPalaceSynthesisEvaluator::DetectContradiction(
	EForensicClueCategory ClueA,
	EForensicClueCategory ClueB) const
{
	// Physical autopsy fact directly contradicts subjective companion dogma
	return (ClueA == EForensicClueCategory::PhysicalAutopsyEvidence && ClueB == EForensicClueCategory::CompanionTestimony) ||
	       (ClueA == EForensicClueCategory::CompanionTestimony && ClueB == EForensicClueCategory::PhysicalAutopsyEvidence);
}
