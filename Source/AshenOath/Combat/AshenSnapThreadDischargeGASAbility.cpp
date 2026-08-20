// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSnapThreadDischargeGASAbility.h"

UAshenSnapThreadDischargeGASAbility::UAshenSnapThreadDischargeGASAbility()
{
	RadialDischargeDamage = 650.0f;
	BlastRadiusUnits = 400.0f;
}

bool UAshenSnapThreadDischargeGASAbility::TriggerThreadSnapDischarge(FVector RuptureLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSnapThreadDischargeGASAbility: THREAD RUPTURE SHOCKWAVE at %s (%.1f DMG, Radius: %.1fuu)!"),
		*RuptureLocation.ToString(), RadialDischargeDamage, BlastRadiusUnits);
	return true;
}
