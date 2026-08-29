// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenAlchemicalSlagAudioSubsystem.h"

UAshenAlchemicalSlagAudioSubsystem::UAshenAlchemicalSlagAudioSubsystem()
{
}

void UAshenAlchemicalSlagAudioSubsystem::EvaluateReactionAcoustics(
	EThermalReactionType Reaction,
	float& OutExplosionBassGain,
	float& OutLiquidSizzleGain,
	float& OutShatterPitchMultiplier) const
{
	switch (Reaction)
	{
	case EThermalReactionType::ConflagrationDeflagration:
		OutExplosionBassGain = 1.00f; // 60Hz Sub-Bass Deflagration Thud
		OutLiquidSizzleGain = 0.85f;
		OutShatterPitchMultiplier = 0.70f;
		break;

	case EThermalReactionType::ThermalShockShatter:
		OutExplosionBassGain = 0.40f;
		OutLiquidSizzleGain = 0.30f;
		OutShatterPitchMultiplier = 1.60f; // High crystalline ice shatter
		break;

	case EThermalReactionType::GalvanicShockBurst:
		OutExplosionBassGain = 0.80f;
		OutLiquidSizzleGain = 0.90f;
		OutShatterPitchMultiplier = 1.20f;
		break;

	case EThermalReactionType::AcidicVaporCloud:
		OutExplosionBassGain = 0.20f;
		OutLiquidSizzleGain = 1.00f; // Sizzling boiling chemical cloud
		OutShatterPitchMultiplier = 0.90f;
		break;

	case EThermalReactionType::None:
	default:
		OutExplosionBassGain = 0.10f;
		OutLiquidSizzleGain = 0.10f;
		OutShatterPitchMultiplier = 1.00f;
		break;
	}
}
