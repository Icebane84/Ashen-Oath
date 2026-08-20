// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenCompanionTacticalWeakpointAbility.h"

UAshenCompanionTacticalWeakpointAbility::UAshenCompanionTacticalWeakpointAbility()
{
}

bool UAshenCompanionTacticalWeakpointAbility::ExecuteWeakpointFlankStrike(AActor* TargetEnemy)
{
	if (!TargetEnemy) return false;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTacticalWeakpointAbility: Executed weakpoint flank strike exploiting Garrett's journal frame data against %s"), *TargetEnemy->GetName());
	return true;
}
