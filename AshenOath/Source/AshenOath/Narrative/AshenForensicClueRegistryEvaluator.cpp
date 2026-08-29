// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenForensicClueRegistryEvaluator.h"

UAshenForensicClueRegistryEvaluator::UAshenForensicClueRegistryEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

float UAshenForensicClueRegistryEvaluator::GetCategoryReliabilityWeight(
	EForensicClueCategory Category) const
{
	if (BalanceDataAsset)
	{
		FEvidenceReliabilityBalancing Reliability = BalanceDataAsset->GetClampedReliability();
		switch (Category)
		{
		case EForensicClueCategory::PhysicalAutopsyEvidence:
			return Reliability.AutopsyReliabilityWeight;
		case EForensicClueCategory::BotanicalChemicalSample:
			return Reliability.ChemicalReliabilityWeight;
		case EForensicClueCategory::HistoricalRunicInscription:
			return Reliability.RunicReliabilityWeight;
		case EForensicClueCategory::CompanionTestimony:
		default:
			return Reliability.TestimonyReliabilityWeight;
		}
	}

	switch (Category)
	{
	case EForensicClueCategory::PhysicalAutopsyEvidence:
		return 1.00f; // Pure physical ground truth
	case EForensicClueCategory::BotanicalChemicalSample:
		return 0.95f;
	case EForensicClueCategory::HistoricalRunicInscription:
		return 0.85f;
	case EForensicClueCategory::CompanionTestimony:
	default:
		return 0.65f; // Subjective bias
	}
}
