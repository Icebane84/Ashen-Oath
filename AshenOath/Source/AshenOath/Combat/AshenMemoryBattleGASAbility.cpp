// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMemoryBattleGASAbility.h"

UAshenMemoryBattleGASAbility::UAshenMemoryBattleGASAbility() {}

bool UAshenMemoryBattleGASAbility::UnleashCatharsisBurst(float ImprintWeightMultiplier)
{
	const float FinalDamage = CatharsisBaseDamage * ImprintWeightMultiplier;
	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleGASAbility: Unleashed Catharsis Burst (Final Damage: %.1f)!"), FinalDamage);
	return true;
}
