// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWrathNecroticCounterGASAbility.h"

UAshenWrathNecroticCounterGASAbility::UAshenWrathNecroticCounterGASAbility()
{
	CounterDamage = 950.0f;
	TaintCorruptionSpike = 5.0f;
}

bool UAshenWrathNecroticCounterGASAbility::ExecuteWrathCounter(AActor* KaelenActor, AActor* TargetEnemy)
{
	if (!KaelenActor || !TargetEnemy) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenWrathNecroticCounterGASAbility: WRATH EXECUTED! Necrotic Counter Slam on %s (%.1f DMG, Taint +%.1f)!"),
		*TargetEnemy->GetName(), CounterDamage, TaintCorruptionSpike);
	return true;
}
