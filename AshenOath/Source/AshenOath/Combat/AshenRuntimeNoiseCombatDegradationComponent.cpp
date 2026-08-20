// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenRuntimeNoiseCombatDegradationComponent.h"

UAshenRuntimeNoiseCombatDegradationComponent::UAshenRuntimeNoiseCombatDegradationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRuntimeNoiseCombatDegradationComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenRuntimeNoiseCombatDegradationComponent::ApplyRuntimeNoiseDegradation(EAshenIntegrationDebtStage Stage)
{
	if (Stage == EAshenIntegrationDebtStage::RuntimeNoise || Stage == EAshenIntegrationDebtStage::ForcedCollapse)
	{
		ParryWindowMultiplier = 0.85f; // 15% narrowing per ENGINE-SPEC-001 Section 2
		StaminaRegenDampening = 0.80f;
	}
	else
	{
		ParryWindowMultiplier = 1.0f;
		StaminaRegenDampening = 1.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenRuntimeNoiseCombatDegradationComponent: Combat degradation applied — ParryWindowMult=%f, StaminaRegen=%f"),
		ParryWindowMultiplier, StaminaRegenDampening);
}
