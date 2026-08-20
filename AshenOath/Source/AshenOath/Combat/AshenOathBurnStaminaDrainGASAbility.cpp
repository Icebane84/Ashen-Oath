// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOathBurnStaminaDrainGASAbility.h"

UAshenOathBurnStaminaDrainGASAbility::UAshenOathBurnStaminaDrainGASAbility() {}

bool UAshenOathBurnStaminaDrainGASAbility::ActivateOathBurnDebuffState()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenOathBurnStaminaDrainGASAbility: GAS Oath Burn debuff active (-2.0/s stamina drain & recovery lock)!"));
	return true;
}
