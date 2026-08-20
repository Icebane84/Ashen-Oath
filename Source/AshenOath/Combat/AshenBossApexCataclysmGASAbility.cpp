// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBossApexCataclysmGASAbility.h"

UAshenBossApexCataclysmGASAbility::UAshenBossApexCataclysmGASAbility()
{
	CataclysmDamage = 1200.0f;
	BlastRadiusUnits = 1500.0f;
}

bool UAshenBossApexCataclysmGASAbility::UnleashApexCataclysm(FVector Origin)
{
	UE_LOG(LogTemp, Error, TEXT("UAshenBossApexCataclysmGASAbility: *** APEX VOID CATACLYSM UNLEASHED at %s (%.1f DMG, Radius: %.1fuu) ***!"),
		*Origin.ToString(), CataclysmDamage, BlastRadiusUnits);
	return true;
}
