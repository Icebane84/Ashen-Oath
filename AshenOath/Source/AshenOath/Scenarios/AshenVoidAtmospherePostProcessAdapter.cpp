// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenVoidAtmospherePostProcessAdapter.h"

UAshenVoidAtmospherePostProcessAdapter::UAshenVoidAtmospherePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenVoidAtmospherePostProcessAdapter::EvaluateWindStreakIntensity(float WindSpeedMps) const
{
	// 15 m/s to 50 m/s scales 0.0 to 1.0 streak blur
	return FMath::Clamp((WindSpeedMps - 15.0f) / 35.0f, 0.0f, 1.0f);
}

float UAshenVoidAtmospherePostProcessAdapter::EvaluateBridgeResonanceGlow(float BridgeStability01) const
{
	return FMath::Clamp(BridgeStability01, 0.0f, 1.0f);
}
