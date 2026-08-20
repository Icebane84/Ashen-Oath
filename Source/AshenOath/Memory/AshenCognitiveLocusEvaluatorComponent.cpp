// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenCognitiveLocusEvaluatorComponent.h"

UAshenCognitiveLocusEvaluatorComponent::UAshenCognitiveLocusEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxResonanceRadius = 1500.0f;
}
void UAshenCognitiveLocusEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenCognitiveLocusEvaluatorComponent::CalculateResonanceIntensity(const FVector& PlayerLocation, const FVector& LocusLocation) const
{
	const float Distance = FVector::Dist(PlayerLocation, LocusLocation);
	if (Distance >= MaxResonanceRadius) return 0.0f;

	const float Normalized = 1.0f - (Distance / MaxResonanceRadius);
	return FMath::Clamp(Normalized, 0.0f, 1.0f);
}

float UAshenCognitiveLocusEvaluatorComponent::EvaluateTraumaDensity(int32 UnsealedTraumaCount, float BaselineInstability) const
{
	const float TraumaFactor = FMath::Clamp(static_cast<float>(UnsealedTraumaCount) * 0.15f, 0.0f, 0.60f);
	const float Density = FMath::Clamp(BaselineInstability + TraumaFactor, 0.0f, 1.0f);
	return Density;
}
