// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSovereignPhoenixShatterAbility.h"

UAshenSovereignPhoenixShatterAbility::UAshenSovereignPhoenixShatterAbility()
{
}

bool UAshenSovereignPhoenixShatterAbility::TriggerSovereignPhoenixShatterWave()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignPhoenixShatterAbility: Triggered sovereign phoenix shatter shockwave (Damage: %f)."), SovereignShatterDamage);
	return true;
}
