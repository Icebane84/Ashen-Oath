// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenCartographerLeylineNodeAbility.h"

UAshenCartographerLeylineNodeAbility::UAshenCartographerLeylineNodeAbility()
{
}

bool UAshenCartographerLeylineNodeAbility::ManifestLeylineSanctuaryPulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCartographerLeylineNodeAbility: Manifested leyline sanctuary pulse (Radius: %f)."), LeylinePulseRadius);
	return true;
}
