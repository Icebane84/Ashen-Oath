// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSovereignPhoenixFlameAscensionAbility.h"

UAshenSovereignPhoenixFlameAscensionAbility::UAshenSovereignPhoenixFlameAscensionAbility()
{
}

bool UAshenSovereignPhoenixFlameAscensionAbility::TriggerSovereignPhoenixFlameAscension()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignPhoenixFlameAscensionAbility: Executed Ascension of the White Flame — Sovereign Phoenix Burst (Damage: %f)."), SovereignWhiteFlameBurstDamage);
	return true;
}
