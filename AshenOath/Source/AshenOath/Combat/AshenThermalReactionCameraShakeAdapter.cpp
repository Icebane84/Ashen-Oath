// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenThermalReactionCameraShakeAdapter.h"

UAshenThermalReactionCameraShakeAdapter::UAshenThermalReactionCameraShakeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenThermalReactionCameraShakeAdapter::EvaluateReactionCameraShake(
	EThermalReactionType Reaction,
	float& OutTraumaKick,
	float& OutRadialBlurIntensity) const
{
	switch (Reaction)
	{
	case EThermalReactionType::ConflagrationDeflagration:
		OutTraumaKick = 0.50f; // Massive explosion kick
		OutRadialBlurIntensity = 0.80f;
		break;

	case EThermalReactionType::GalvanicShockBurst:
		OutTraumaKick = 0.40f;
		OutRadialBlurIntensity = 0.60f;
		break;

	case EThermalReactionType::ThermalShockShatter:
		OutTraumaKick = 0.35f;
		OutRadialBlurIntensity = 0.50f;
		break;

	case EThermalReactionType::AcidicVaporCloud:
		OutTraumaKick = 0.15f;
		OutRadialBlurIntensity = 0.30f;
		break;

	case EThermalReactionType::None:
	default:
		OutTraumaKick = 0.0f;
		OutRadialBlurIntensity = 0.0f;
		break;
	}
}
