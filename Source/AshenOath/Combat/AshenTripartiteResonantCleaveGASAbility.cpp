// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTripartiteResonantCleaveGASAbility.h"

UAshenTripartiteResonantCleaveGASAbility::UAshenTripartiteResonantCleaveGASAbility()
{
	BaseFinisherDamage = 1400.0f;
	DebtClearingPercentage = 0.30f;
}

bool UAshenTripartiteResonantCleaveGASAbility::ExecuteResonantCleave(AActor* TargetActor)
{
	if (!TargetActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteResonantCleaveGASAbility: TRIPARTITE RESONANT CLEAVE EXECUTED on %s! (%.1f DMG, -%.1f%% Debt)!"),
		*TargetActor->GetName(), BaseFinisherDamage, DebtClearingPercentage * 100.0f);
	return true;
}
