// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 721: Ashen Serafina Divine Judgment Ability

#include "AshenSerafinaDivineJudgmentAbility.h"

void UAshenSerafinaDivineJudgmentAbility::ExecuteDivineJudgment(AActor* TargetEnemy, float BaseRadiantDamage)
{
	if (!TargetEnemy) return;

	OnDivineJudgmentExecuted.Broadcast(TargetEnemy, BaseRadiantDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaDivineJudgmentAbility: DIVINE JUDGMENT EXECUTED -> Target Enemy '%s' struck for %.1f Radiant Damage."),
		*TargetEnemy->GetName(), BaseRadiantDamage);
}
