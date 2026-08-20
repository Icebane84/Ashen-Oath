// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenLivingOathGASAbility.h"

UAshenLivingOathGASAbility::UAshenLivingOathGASAbility() {}

bool UAshenLivingOathGASAbility::ActivateOathStrike(EAshenLivingOathType OathType)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenLivingOathGASAbility: Activated Oath Resonance Strike for Oath Type %d (Bonus Damage: %.1f)!"),
		(int32)OathType, OathResonanceBonusDamage);
	return true;
}
