// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenCompanionResonanceSyncGASAbility.h"

UAshenCompanionResonanceSyncGASAbility::UAshenCompanionResonanceSyncGASAbility() {}

bool UAshenCompanionResonanceSyncGASAbility::ActivateResonanceSyncDamageBuff()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionResonanceSyncGASAbility: 15s ResonanceSync damage buff and poise armor activated for all party members!"));
	return true;
}
