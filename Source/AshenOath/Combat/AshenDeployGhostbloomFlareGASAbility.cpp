// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenDeployGhostbloomFlareGASAbility.h"

UAshenDeployGhostbloomFlareGASAbility::UAshenDeployGhostbloomFlareGASAbility()
{
	FlareThrowDistanceUnits = 750.0f;
}

bool UAshenDeployGhostbloomFlareGASAbility::LobFlashFlare(AActor* GarrettActor, FVector TargetLocation)
{
	if (!GarrettActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenDeployGhostbloomFlareGASAbility: LOBBED GHOSTBLOOM FLARE to %s!"),
		*TargetLocation.ToString());
	return true;
}
