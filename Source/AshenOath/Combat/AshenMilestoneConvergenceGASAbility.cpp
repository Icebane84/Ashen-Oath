// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMilestoneConvergenceGASAbility.h"

UAshenMilestoneConvergenceGASAbility::UAshenMilestoneConvergenceGASAbility()
{
	MilestoneFinisherDamage = 2500.0f;
}

bool UAshenMilestoneConvergenceGASAbility::TriggerMilestoneConvergence(AActor* InstigatorActor, FName BossEncounterID)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMilestoneConvergenceGASAbility: TRIGGERED TIER III MILESTONE CONVERGENCE for %s (Damage: %.1f)!"),
		*BossEncounterID.ToString(), MilestoneFinisherDamage);
	return true;
}
