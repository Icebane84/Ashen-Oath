// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Narrative/AshenForensicMindscapeBalanceDataAsset.h"

FForensicDeductionBalancing UAshenForensicMindscapeBalanceDataAsset::GetClampedDeduction() const
{
	FForensicDeductionBalancing Clamped = DeductionBalancing;
	Clamped.ResolutionSynthesisThreshold = FMath::Clamp(Clamped.ResolutionSynthesisThreshold, 0.50f, 1.00f);
	Clamped.ClueBaseWeightMultiplier = FMath::Clamp(Clamped.ClueBaseWeightMultiplier, 0.10f, 0.80f);
	Clamped.SolvedCaseSanityCatharsis = FMath::Clamp(Clamped.SolvedCaseSanityCatharsis, 10.0f, 100.0f);
	return Clamped;
}

FEvidenceReliabilityBalancing UAshenForensicMindscapeBalanceDataAsset::GetClampedReliability() const
{
	FEvidenceReliabilityBalancing Clamped = ReliabilityBalancing;
	Clamped.AutopsyReliabilityWeight = FMath::Clamp(Clamped.AutopsyReliabilityWeight, 0.50f, 1.00f);
	Clamped.ChemicalReliabilityWeight = FMath::Clamp(Clamped.ChemicalReliabilityWeight, 0.50f, 1.00f);
	Clamped.RunicReliabilityWeight = FMath::Clamp(Clamped.RunicReliabilityWeight, 0.40f, 1.00f);
	Clamped.TestimonyReliabilityWeight = FMath::Clamp(Clamped.TestimonyReliabilityWeight, 0.20f, 1.00f);
	return Clamped;
}
