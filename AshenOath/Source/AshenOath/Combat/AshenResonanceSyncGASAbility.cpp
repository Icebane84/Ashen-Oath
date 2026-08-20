// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenResonanceSyncGASAbility.h"

UAshenResonanceSyncGASAbility::UAshenResonanceSyncGASAbility()
{
	ResonanceDuration = 30.0f;
	DamageMultiplierBonus = 0.15f;
}

bool UAshenResonanceSyncGASAbility::UnleashResonanceSurge(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenResonanceSyncGASAbility: Unleashed Resonance Surge! (+%.0f%% Damage for %.0fs)."),
		DamageMultiplierBonus * 100.0f, ResonanceDuration);
	return true;
}
