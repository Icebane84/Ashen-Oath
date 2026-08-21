// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenHarmonizedFinisherOrchestratorComponent.h"

UAshenHarmonizedFinisherOrchestratorComponent::UAshenHarmonizedFinisherOrchestratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenHarmonizedFinisherOrchestratorComponent::CalculateFinisherDamage(
	float BaseDamage,
	EHarmonizedFinisherTier Tier) const
{
	switch (Tier)
	{
	case EHarmonizedFinisherTier::StandardTripartite:
		return BaseDamage * 3.0f;
	case EHarmonizedFinisherTier::RadiantCatharsis:
		return BaseDamage * 3.5f;
	case EHarmonizedFinisherTier::TranscendentOath:
		return BaseDamage * 4.5f;
	default:
		return BaseDamage * 2.0f;
	}
}
