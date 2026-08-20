// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenLorekeeperBeaconGASAbility.h"

UAshenLorekeeperBeaconGASAbility::UAshenLorekeeperBeaconGASAbility()
{
	SanityCost = 20.0f;
	IlluminationRadius = 1500.0f;
}

bool UAshenLorekeeperBeaconGASAbility::CastLorekeeperBeacon(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenLorekeeperBeaconGASAbility: Cast Lorekeeper Beacon (Radius: %.1fuu, Cost: %.1f Sanity)."),
		IlluminationRadius, SanityCost);
	return true;
}
