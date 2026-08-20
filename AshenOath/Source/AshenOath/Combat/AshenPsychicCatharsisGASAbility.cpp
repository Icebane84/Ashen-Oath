// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPsychicCatharsisGASAbility.h"

UAshenPsychicCatharsisGASAbility::UAshenPsychicCatharsisGASAbility()
{
	CatharsisBaseDamage = 600.0f;
	ResolveRestored = 30.0f;
	BlastRadius = 900.0f;
}

bool UAshenPsychicCatharsisGASAbility::UnleashPsychicCatharsis(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenPsychicCatharsisGASAbility: Unleashed Psychic Catharsis (DMG: %.1f, Resolve Gain: +%.1f, Radius: %.1fuu)!"),
		CatharsisBaseDamage, ResolveRestored, BlastRadius);
	return true;
}
