// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSanctifiedGroundPulseGASAbility.h"

UAshenSanctifiedGroundPulseGASAbility::UAshenSanctifiedGroundPulseGASAbility()
{
	SanctificationRadiusUnits = 800.0f;
}

bool UAshenSanctifiedGroundPulseGASAbility::ConsecrateGroundZone(FVector SlamLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctifiedGroundPulseGASAbility: GROUND CONSECRATION PULSE at %s (Radius: %.1fuu)!"),
		*SlamLocation.ToString(), SanctificationRadiusUnits);
	return true;
}
