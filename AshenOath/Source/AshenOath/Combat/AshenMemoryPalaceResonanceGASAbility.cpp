// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMemoryPalaceResonanceGASAbility.h"

UAshenMemoryPalaceResonanceGASAbility::UAshenMemoryPalaceResonanceGASAbility()
{
	ResonancePulseRadius = 1800.0f;
}

bool UAshenMemoryPalaceResonanceGASAbility::UnleashResonancePulse(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryPalaceResonanceGASAbility: Unleashed Memory Palace Resonance Pulse across %.1fuu radius!"),
		ResonancePulseRadius);
	return true;
}
