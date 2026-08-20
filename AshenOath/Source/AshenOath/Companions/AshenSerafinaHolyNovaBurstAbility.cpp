// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 724: Ashen Serafina Holy Nova Burst Ability

#include "AshenSerafinaHolyNovaBurstAbility.h"

void UAshenSerafinaHolyNovaBurstAbility::ExecuteHolyNovaBurst(FVector Location, float KnockbackPower)
{
	OnHolyNovaExecuted.Broadcast(Location, KnockbackPower);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaHolyNovaBurstAbility: HOLY NOVA BURST EXECUTED -> Center: (%s) | Knockback Power: %.0f."),
		*Location.ToString(), KnockbackPower);
}
