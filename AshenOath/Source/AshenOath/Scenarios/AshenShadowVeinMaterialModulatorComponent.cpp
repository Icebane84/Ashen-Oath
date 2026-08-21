// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenShadowVeinMaterialModulatorComponent.h"

UAshenShadowVeinMaterialModulatorComponent::UAshenShadowVeinMaterialModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenShadowVeinMaterialModulatorComponent::EvaluateShadowVeinOpacity(
	float IntegrationDebt,
	float Corruption) const
{
	return FMath::Clamp((IntegrationDebt * 0.60f) + (Corruption * 0.40f), 0.0f, 1.0f);
}

float UAshenShadowVeinMaterialModulatorComponent::EvaluateTraumaJitterFrequency(
	float BossProximityCentimeters,
	float MaxProximity) const
{
	if (MaxProximity <= 0.0f)
	{
		return 0.0f;
	}

	const float ClampedProx = FMath::Clamp(BossProximityCentimeters, 0.0f, MaxProximity);
	const float Normalized = 1.0f - (ClampedProx / MaxProximity); // Closer = higher jitter
	return Normalized * 12.0f; // 0 to 12 Hz trauma jitter
}
