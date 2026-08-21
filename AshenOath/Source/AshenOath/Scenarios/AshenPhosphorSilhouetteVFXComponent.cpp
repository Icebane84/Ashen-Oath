// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenPhosphorSilhouetteVFXComponent.h"

UAshenPhosphorSilhouetteVFXComponent::UAshenPhosphorSilhouetteVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenPhosphorSilhouetteVFXComponent::EvaluateSilhouetteContrast(
	float FlareIntensity,
	float AmbientDarkness) const
{
	return FMath::Clamp((FlareIntensity * 0.70f) + (AmbientDarkness * 0.30f), 0.0f, 1.0f);
}
