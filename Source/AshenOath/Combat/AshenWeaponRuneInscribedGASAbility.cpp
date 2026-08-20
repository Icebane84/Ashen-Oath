// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWeaponRuneInscribedGASAbility.h"

UAshenWeaponRuneInscribedGASAbility::UAshenWeaponRuneInscribedGASAbility() {}

bool UAshenWeaponRuneInscribedGASAbility::ActivateRuneBurst(int32 RuneTier)
{
	const float FinalDamage = RuneResonanceDamage * (1.0f + 0.25f * (float)RuneTier);
	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaponRuneInscribedGASAbility: Inscribed Rune Burst activated for Tier %d (Damage: %.1f)!"),
		RuneTier, FinalDamage);
	return true;
}
