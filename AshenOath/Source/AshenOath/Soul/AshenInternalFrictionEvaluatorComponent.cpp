// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenInternalFrictionEvaluatorComponent.h"

UAshenInternalFrictionEvaluatorComponent::UAshenInternalFrictionEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenInternalFrictionEvaluatorComponent::EvaluateInternalFriction(
	const FCanonicalSoulStateVector& SoulState,
	float ThreatIntensity) const
{
	const float LensDistance = AshenContractUtils::GetLensDistance(SoulState.DominantLens, SoulState.PreviousDominantLens);

	// Formula: Clamp(0.40*D + 0.30*N + 0.30*DeltaL + 0.20*Threat - 0.20*R, 0.0, 1.0)
	const float RawFriction =
		(0.40f * SoulState.IntegrationDebt) +
		(0.30f * SoulState.AccumulatedDysregulation) +
		(0.30f * LensDistance) +
		(0.20f * FMath::Clamp(ThreatIntensity, 0.0f, 1.0f)) -
		(0.20f * SoulState.Resolve);

	return FMath::Clamp(RawFriction, 0.0f, 1.0f);
}

int32 UAshenInternalFrictionEvaluatorComponent::GetCurrentDysregulationStage(const FCanonicalSoulStateVector& SoulState) const
{
	return AshenContractUtils::GetDysregulationStage(SoulState.AccumulatedDysregulation);
}

bool UAshenInternalFrictionEvaluatorComponent::IsInSupportedStruggleBand(float InternalFriction, float RelationalFlow) const
{
	return (InternalFriction >= SupportedStruggleFrictionThreshold) && (RelationalFlow >= SupportedStruggleFlowThreshold);
}
