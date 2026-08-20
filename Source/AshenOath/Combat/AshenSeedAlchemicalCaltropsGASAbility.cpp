// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSeedAlchemicalCaltropsGASAbility.h"

UAshenSeedAlchemicalCaltropsGASAbility::UAshenSeedAlchemicalCaltropsGASAbility()
{
	SeedingRadiusUnits = 400.0f;
}

bool UAshenSeedAlchemicalCaltropsGASAbility::SeedCaltropCorridor(AActor* GarrettActor, FVector SeedCenterLocation)
{
	if (!GarrettActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenSeedAlchemicalCaltropsGASAbility: SEEDED CALTROPS at %s (Radius: %.1fuu)!"),
		*SeedCenterLocation.ToString(), SeedingRadiusUnits);
	return true;
}
