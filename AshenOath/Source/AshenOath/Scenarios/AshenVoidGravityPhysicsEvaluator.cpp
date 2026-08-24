// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenVoidGravityPhysicsEvaluator.h"

UAshenVoidGravityPhysicsEvaluator::UAshenVoidGravityPhysicsEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenVoidGravityPhysicsEvaluator::EvaluateJumpDistanceMultiplier(float GravityScale) const
{
	const float SafeG = FMath::Clamp(GravityScale, 0.10f, 2.0f);
	// 1.0g -> 1.0x, 0.1g -> 3.0x
	if (SafeG <= 1.0f)
	{
		const float Alpha = (1.0f - SafeG) / 0.90f;
		return FMath::Lerp(1.0f, 3.0f, Alpha);
	}
	else
	{
		// Heavy gravity reduces jump
		return FMath::Max(0.5f, 1.0f / SafeG);
	}
}

float UAshenVoidGravityPhysicsEvaluator::EvaluateDownwardStrikeMultiplier(float GravityScale) const
{
	// Falling from high void gravity arc accumulates massive downward momentum (up to 2.5x)
	const float SafeG = FMath::Clamp(GravityScale, 0.10f, 1.50f);
	if (SafeG < 1.0f)
	{
		// Low g allows higher jumps, leading to greater terminal slam force
		const float Alpha = (1.0f - SafeG) / 0.90f;
		return FMath::Lerp(1.0f, 2.5f, Alpha);
	}
	return 1.0f;
}
