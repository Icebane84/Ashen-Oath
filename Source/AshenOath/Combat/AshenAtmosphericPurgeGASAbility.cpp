// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAtmosphericPurgeGASAbility.h"

UAshenAtmosphericPurgeGASAbility::UAshenAtmosphericPurgeGASAbility()
{
	PurgeRadius = 1000.0f;
	PurgeBuffDuration = 15.0f;
	ResolveCost = 20.0f;
}

bool UAshenAtmosphericPurgeGASAbility::UnleashAtmosphericPurge(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenAtmosphericPurgeGASAbility: Unleashed Atmospheric Purge (Radius: %.1fuu, Duration: %.1fs, Cost: %.1f Resolve)."),
		PurgeRadius, PurgeBuffDuration, ResolveCost);
	return true;
}
