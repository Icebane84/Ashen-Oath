// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenParryCounterExecutionGASAbility.h"

UAshenParryCounterExecutionGASAbility::UAshenParryCounterExecutionGASAbility() {}

bool UAshenParryCounterExecutionGASAbility::TriggerParryWindow()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenParryCounterExecutionGASAbility: Parry window opened for %.2fs."), ParryWindowDuration);
	return true;
}

bool UAshenParryCounterExecutionGASAbility::ResolveParryHit(AActor* AttackerActor, float IncomingPoiseDamage)
{
	const bool bOpensExecution = IncomingPoiseDamage >= 50.0f;
	if (OnParrySuccessful.IsBound())
	{
		OnParrySuccessful.Broadcast(AttackerActor, bOpensExecution);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenParryCounterExecutionGASAbility: PARRY SUCCESSFUL against %s! SlowMo: %.2fx | Execution Window: %s"),
		AttackerActor ? *AttackerActor->GetName() : TEXT("Unknown"), SlowMoTimeDilation, bOpensExecution ? TEXT("OPEN") : TEXT("CLOSED"));
	return true;
}
