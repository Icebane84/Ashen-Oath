// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenResonantBeaconEchoGASAbility.h"

UAshenResonantBeaconEchoGASAbility::UAshenResonantBeaconEchoGASAbility() {}

bool UAshenResonantBeaconEchoGASAbility::TriggerBeaconPulse(FVector PlayerLocation, FVector SanctuaryLocation)
{
	const float Dist = FVector::Dist(PlayerLocation, SanctuaryLocation);
	UE_LOG(LogTemp, Warning, TEXT("UAshenResonantBeaconEchoGASAbility: CELESTIAL BEACON PULSE -> Distance to Sanctuary: %.1fuu!"), Dist);
	return true;
}
