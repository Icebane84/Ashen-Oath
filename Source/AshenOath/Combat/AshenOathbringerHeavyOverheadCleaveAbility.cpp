// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 782: Ashen Oathbringer Heavy Overhead Cleave Ability

#include "AshenOathbringerHeavyOverheadCleaveAbility.h"

void UAshenOathbringerHeavyOverheadCleaveAbility::ExecuteHeavyOverheadCleave(AActor* TargetEnemy, float BaseCleaveDamage)
{
	OnOverheadCleaveExecuted.Broadcast(TargetEnemy, BaseCleaveDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerHeavyOverheadCleaveAbility: HEAVY OVERHEAD CLEAVE EXECUTED -> Target: '%s' | Cleave Damage: %.1f HP."),
		TargetEnemy ? *TargetEnemy->GetName() : TEXT("Ground/Area"), BaseCleaveDamage);
}
