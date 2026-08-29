// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenAlchemicalSlagHapticBridge.h"

UAshenAlchemicalSlagHapticBridge::UAshenAlchemicalSlagHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAlchemicalSlagHapticBridge::EvaluateReactionHaptics(
	EThermalReactionType Reaction,
	float& OutHeavyMotorGain,
	float& OutLightMotorGain)
{
	switch (Reaction)
	{
	case EThermalReactionType::ConflagrationDeflagration:
		OutHeavyMotorGain = 0.95f; // Full DualSense explosion blast
		OutLightMotorGain = 0.40f;
		break;

	case EThermalReactionType::GalvanicShockBurst:
		OutHeavyMotorGain = 0.85f;
		OutLightMotorGain = 0.90f; // High frequency arc tingle
		break;

	case EThermalReactionType::ThermalShockShatter:
		OutHeavyMotorGain = 0.60f;
		OutLightMotorGain = 0.85f; // Sharp crystalline crackle
		break;

	case EThermalReactionType::AcidicVaporCloud:
		OutHeavyMotorGain = 0.25f;
		OutLightMotorGain = 0.70f; // Sizzling boiling purr
		break;

	case EThermalReactionType::None:
	default:
		OutHeavyMotorGain = 0.10f;
		OutLightMotorGain = 0.10f;
		break;
	}
}
