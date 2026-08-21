// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Haptics/AshenSomaticFrictionHapticBridge.h"

UAshenSomaticFrictionHapticBridge::UAshenSomaticFrictionHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FDualSenseTriggerConfig UAshenSomaticFrictionHapticBridge::BuildSomaticTriggerConfig(
	float EffectiveMassKg,
	float DysregulationScalar) const
{
	FDualSenseTriggerConfig Config;
	Config.Mode = EHapticTriggerEffectMode::Feedback;
	Config.Priority = ETriggerPriorityLevel::Priority3_AmbientSomatic;
	Config.StartPosition = 0.1f;

	// Scale resistance with weapon mass (45 - 200kg) + dysregulation (0.0 - 1.0)
	const float MassRatio = FMath::Clamp((EffectiveMassKg - 45.0f) / 155.0f, 0.0f, 1.0f);
	const float CombinedResistance = (MassRatio * 0.6f) + (FMath::Clamp(DysregulationScalar, 0.0f, 1.0f) * 0.4f);

	Config.ResistanceForce = FMath::Clamp(CombinedResistance, 0.10f, 0.95f);
	Config.VibrationFrequencyHz = 0.0f;
	return Config;
}
