// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenIntegrationDebtPipelineComponent.h"

UAshenIntegrationDebtPipelineComponent::UAshenIntegrationDebtPipelineComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentIntegrationDebt = 0.0f;
}
void UAshenIntegrationDebtPipelineComponent::BeginPlay() { Super::BeginPlay(); }

EIntegrationDebtStage UAshenIntegrationDebtPipelineComponent::EvaluateDebtStage(float InDebt)
{
	CurrentIntegrationDebt = FMath::Clamp(InDebt, 0.0f, 100.0f);
	if (CurrentIntegrationDebt >= 100.0f)
	{
		return EIntegrationDebtStage::ForcedCollapse;
	}
	else if (CurrentIntegrationDebt >= 75.0f)
	{
		return EIntegrationDebtStage::RuntimeNoise;
	}
	else if (CurrentIntegrationDebt >= 50.0f)
	{
		return EIntegrationDebtStage::MemoryBleed;
	}
	return EIntegrationDebtStage::Dormant;
}

float UAshenIntegrationDebtPipelineComponent::CalculateParryWindowPenalty(float BaseWindowSeconds) const
{
	if (CurrentIntegrationDebt >= 75.0f)
	{
		return BaseWindowSeconds * 0.65f; // -35% parry window penalty during Runtime Noise
	}
	return BaseWindowSeconds;
}
