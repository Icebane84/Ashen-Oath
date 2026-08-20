// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticPostureShatterAbility.h"

UAshenSomaticPostureShatterAbility::UAshenSomaticPostureShatterAbility()
{
}

bool UAshenSomaticPostureShatterAbility::TriggerSomaticPostureShatterStrike()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPostureShatterAbility: Triggered somatic posture shatter strike (Damage: %f)."), PostureShatterDamage);
	return true;
}
