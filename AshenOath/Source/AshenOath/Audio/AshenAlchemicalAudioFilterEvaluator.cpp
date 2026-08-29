// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenAlchemicalAudioFilterEvaluator.h"

UAshenAlchemicalAudioFilterEvaluator::UAshenAlchemicalAudioFilterEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	BalanceDataAsset = nullptr;
}

float UAshenAlchemicalAudioFilterEvaluator::EvaluateLPFCutoffHz(EAlchemicalAudioFilter Filter) const
{
	switch (Filter)
	{
	case EAlchemicalAudioFilter::SmokeLowPass450Hz:
		if (BalanceDataAsset)
		{
			return BalanceDataAsset->GetClampedFilterBalancing().SmokeLowPassCutoffHz;
		}
		return 450.0f; // Dense sulfurous fog
	case EAlchemicalAudioFilter::GloomwoodChill:
		return 3500.0f;
	default:
		return 20000.0f; // Unfiltered
	}
}

float UAshenAlchemicalAudioFilterEvaluator::EvaluateSideChainDuckingDB(EAlchemicalAudioFilter Filter) const
{
	switch (Filter)
	{
	case EAlchemicalAudioFilter::TackleSideChain:
		if (BalanceDataAsset)
		{
			return BalanceDataAsset->GetClampedFilterBalancing().TackleSideChainDuckingDB;
		}
		return -24.0f; // Heavy ducking during bone-slam
	default:
		return 0.0f;
	}
}

float UAshenAlchemicalAudioFilterEvaluator::EvaluatePitchOffsetSemitones(EAlchemicalAudioFilter Filter) const
{
	switch (Filter)
	{
	case EAlchemicalAudioFilter::GloomwoodChill:
		if (BalanceDataAsset)
		{
			return BalanceDataAsset->GetClampedFilterBalancing().GloomwoodPitchOffsetSemitones;
		}
		return -12.0f;
	default:
		return 0.0f;
	}
}
