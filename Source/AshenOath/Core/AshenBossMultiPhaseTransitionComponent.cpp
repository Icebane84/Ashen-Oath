// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 476: Ashen Boss Multi-Phase Transition Component

#include "AshenBossMultiPhaseTransitionComponent.h"

UAshenBossMultiPhaseTransitionComponent::UAshenBossMultiPhaseTransitionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentPhaseIndex = 1;
}

void UAshenBossMultiPhaseTransitionComponent::EvaluateBossPhaseTransition(float CurrentHealth, float MaxHealth)
{
	const float SafeMax = FMath::Max(1.0f, MaxHealth);
	const float HealthPercent = CurrentHealth / SafeMax;

	if (CurrentPhaseIndex == 1 && HealthPercent <= 0.50f)
	{
		CurrentPhaseIndex = 2;
		OnPhaseTransitioned.Broadcast(2, 0.50f);

		UE_LOG(LogTemp, Warning, TEXT("UAshenBossMultiPhaseTransitionComponent: BOSS PHASE TRANSITION TRIGGERED -> PHASE 2 INITIATED (Health <= 50%%)."));
	}
	else if (CurrentPhaseIndex == 2 && HealthPercent <= 0.20f)
	{
		CurrentPhaseIndex = 3;
		OnPhaseTransitioned.Broadcast(3, 0.20f);

		UE_LOG(LogTemp, Error, TEXT("UAshenBossMultiPhaseTransitionComponent: BOSS PHASE TRANSITION TRIGGERED -> PHASE 3 DESPERATION MODE INITIATED (Health <= 20%%)."));
	}
}
