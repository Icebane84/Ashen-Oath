// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 708: Ashen Garrett Assassination Dash Ability

#include "AshenGarrettAssassinationDashAbility.h"

void UAshenGarrettAssassinationDashAbility::ExecuteAssassinationDash(AActor* TargetEnemy, float BaseDashDamage)
{
	if (!TargetEnemy) return;

	OnDashExecuted.Broadcast(TargetEnemy, BaseDashDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettAssassinationDashAbility: ASSASSINATION DASH EXECUTED -> Enemy '%s' struck for %.1f HP."),
		*TargetEnemy->GetName(), BaseDashDamage);
}
