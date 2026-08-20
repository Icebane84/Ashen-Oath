// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticIdentityShatterAbility.h"

UAshenSomaticIdentityShatterAbility::UAshenSomaticIdentityShatterAbility()
{
}

bool UAshenSomaticIdentityShatterAbility::TriggerSomaticIdentityShatterWave()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticIdentityShatterAbility: Triggered somatic identity shatter wave (Damage: %f)."), IdentityShatterDamage);
	return true;
}
