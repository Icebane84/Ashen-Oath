// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenGloomwoodStabilizationDirectorComponent.h"

UAshenGloomwoodStabilizationDirectorComponent::UAshenGloomwoodStabilizationDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	NeedleInventoryCount = 3;
}

float UAshenGloomwoodStabilizationDirectorComponent::AdministerGloomwoodNeedle(EGloomwoodStabilizationTier Tier)
{
	if (NeedleInventoryCount > 0)
	{
		NeedleInventoryCount--;
	}

	return EvaluateAudioPitchSemitones(true, Tier);
}

float UAshenGloomwoodStabilizationDirectorComponent::EvaluateAudioPitchSemitones(
	bool bIsFrozen,
	EGloomwoodStabilizationTier Tier) const
{
	if (!bIsFrozen)
	{
		return 0.0f;
	}

	switch (Tier)
	{
	case EGloomwoodStabilizationTier::ConcentratedSap:
		return -18.0f;
	case EGloomwoodStabilizationTier::PurifiedElixir:
		return -24.0f;
	case EGloomwoodStabilizationTier::StandardSap:
	default:
		return -12.0f;
	}
}
