// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSomaticVeinCreepShaderEvaluatorComponent.h"

UAshenSomaticVeinCreepShaderEvaluatorComponent::UAshenSomaticVeinCreepShaderEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSomaticVeinCreepShaderEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenSomaticVeinCreepShaderEvaluatorComponent::CalculateVeinCreepScalar(float Corruption, float IntegrationDebt) const
{
	const float Combined = (Corruption * 0.60f) + (IntegrationDebt * 0.40f);
	const float Scalar = FMath::Clamp(Combined, 0.0f, 1.0f);
	return Scalar;
}

bool UAshenSomaticVeinCreepShaderEvaluatorComponent::IsEmissiveShadowGlowActive(float VeinCreepScalar) const
{
	return (VeinCreepScalar >= 0.80f);
}
