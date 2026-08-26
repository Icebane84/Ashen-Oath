// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenWeatherHapticBridge.h"

UAshenWeatherHapticBridge::UAshenWeatherHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWeatherHapticBridge::EvaluateWeatherHaptics(
	EWeatherHazardState State,
	float WindShearMps,
	EWeatherShelterType Shelter,
	float& OutWindDragTriggerResistance,
	float& OutRainDropTickleGain,
	float& OutLightningShockImpulse)
{
	if (Shelter == EWeatherShelterType::HearthSanctuary)
	{
		OutWindDragTriggerResistance = 0.0f;
		OutRainDropTickleGain = 0.0f;
		OutLightningShockImpulse = 0.0f;
		return;
	}

	// Wind shear trigger drag resistance
	const float WindRatio = FMath::Clamp(WindShearMps / 40.0f, 0.0f, 1.0f);
	OutWindDragTriggerResistance = 0.25f + (WindRatio * 0.65f); // 0.25 to 0.90

	// Rain drop tickle gain
	OutRainDropTickleGain = (State == EWeatherHazardState::AcidRainCorrosion) ? 0.85f : 0.0f;

	// Lightning shock impulse
	OutLightningShockImpulse = (State == EWeatherHazardState::LightningSurge) ? 0.70f : 0.0f;
}
