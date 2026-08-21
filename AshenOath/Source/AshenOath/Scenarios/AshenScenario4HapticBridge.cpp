// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario4HapticBridge.h"

UAshenScenario4HapticBridge::UAshenScenario4HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenScenario4HapticBridge::EvaluateSootSwipeHapticIntensity(
	float SwipeVelocity,
	float RemainingSoot) const
{
	// Velocity + grit resistance of soot
	const float BaseFriction = FMath::Clamp(SwipeVelocity * 0.50f, 0.0f, 0.50f);
	const float Grit = FMath::Clamp(RemainingSoot * 0.40f, 0.0f, 0.40f);
	return FMath::Clamp(BaseFriction + Grit, 0.0f, 0.90f);
}
