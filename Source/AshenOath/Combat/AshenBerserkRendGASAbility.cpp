// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBerserkRendGASAbility.h"

UAshenBerserkRendGASAbility::UAshenBerserkRendGASAbility()
{
	ComboHitsDamage.Add(120.0f);
	ComboHitsDamage.Add(180.0f);
	ComboHitsDamage.Add(300.0f);
	AttackSpeedAccelerationPerHit = 0.10f;
}

float UAshenBerserkRendGASAbility::CalculateComboDamage(int32 HitIndex, float& OutSpeedBonus) const
{
	if (!ComboHitsDamage.IsValidIndex(HitIndex))
	{
		OutSpeedBonus = 0.0f;
		return 0.0f;
	}

	OutSpeedBonus = static_cast<float>(HitIndex) * AttackSpeedAccelerationPerHit;
	const float BaseDamage = ComboHitsDamage[HitIndex];
	const float FinalDamage = BaseDamage * (1.0f + OutSpeedBonus);

	UE_LOG(LogTemp, Log, TEXT("UAshenBerserkRendGASAbility: Combo Hit %d -> Damage: %.1f, Speed Bonus: +%.0f%%"),
		HitIndex + 1, FinalDamage, OutSpeedBonus * 100.0f);

	return FinalDamage;
}
