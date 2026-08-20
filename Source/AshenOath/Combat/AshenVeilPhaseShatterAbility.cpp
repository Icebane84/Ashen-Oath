// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenVeilPhaseShatterAbility.h"

UAshenVeilPhaseShatterAbility::UAshenVeilPhaseShatterAbility()
{
}

bool UAshenVeilPhaseShatterAbility::TriggerVeilPhaseShatterStrike()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenVeilPhaseShatterAbility: Triggered dimensional veil phase shatter strike (Damage: %f)."), PhaseShatterDamage);
	return true;
}
