// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenDualTriggerLockEvaluatorComponent.h"

UAshenDualTriggerLockEvaluatorComponent::UAshenDualTriggerLockEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MinTravelTolerance = 0.45f;
	MaxTravelTolerance = 0.55f;
}
void UAshenDualTriggerLockEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenDualTriggerLockEvaluatorComponent::EvaluateTriggerLock(float L2Travel, float R2Travel, float& OutCorruptionSlipDelta)
{
	const bool bL2InTolerance = (L2Travel >= MinTravelTolerance && L2Travel <= MaxTravelTolerance);
	const bool bR2InTolerance = (R2Travel >= MinTravelTolerance && R2Travel <= MaxTravelTolerance);

	if (bL2InTolerance && bR2InTolerance)
	{
		OutCorruptionSlipDelta = 0.0f;
		return true;
	}

	// Focus slips: accelerated corruption growth (+0.05/sec)
	OutCorruptionSlipDelta = 0.05f;
	UE_LOG(LogTemp, Warning, TEXT("UAshenDualTriggerLockEvaluatorComponent: Trigger lock slipped (L2: %.2f, R2: %.2f) -> Corruption Acceleration +0.05!"),
		L2Travel, R2Travel);

	return false;
}
