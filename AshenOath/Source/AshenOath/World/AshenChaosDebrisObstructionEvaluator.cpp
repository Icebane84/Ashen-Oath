// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenChaosDebrisObstructionEvaluator.h"

UAshenChaosDebrisObstructionEvaluator::UAshenChaosDebrisObstructionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenChaosDebrisObstructionEvaluator::EvaluateNavmeshBlockingRadius(float DebrisMassKg) const
{
	const float ClampedMass = FMath::Max(0.0f, DebrisMassKg);
	return FMath::Clamp(150.0f + (ClampedMass * 2.5f), 150.0f, 800.0f);
}

ENavmeshObstructionState UAshenChaosDebrisObstructionEvaluator::ClassifyObstructionState(float DebrisHeightUU) const
{
	if (DebrisHeightUU <= 10.0f)
	{
		return ENavmeshObstructionState::ClearPath;
	}
	else if (DebrisHeightUU <= 120.0f)
	{
		return ENavmeshObstructionState::VaultableLowDebris;
	}

	return ENavmeshObstructionState::BlockedHighRubble;
}
