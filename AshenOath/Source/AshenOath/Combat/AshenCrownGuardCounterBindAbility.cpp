// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 663: Ashen Crown Guard Counter Bind Ability

#include "AshenCrownGuardCounterBindAbility.h"

void UAshenCrownGuardCounterBindAbility::ExecuteCrownGuardCounter(AActor* TargetEnemy)
{
	if (!TargetEnemy) return;

	const bool bDisarm = true;
	OnCounterExecuted.Broadcast(TargetEnemy, bDisarm);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCrownGuardCounterBindAbility: CROWN GUARD COUNTER-BIND EXECUTED -> Target '%s' disarmed."),
		*TargetEnemy->GetName());
}
