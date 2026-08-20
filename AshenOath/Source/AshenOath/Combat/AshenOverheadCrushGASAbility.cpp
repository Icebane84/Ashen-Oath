// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenOverheadCrushGASAbility.h"

UAshenOverheadCrushGASAbility::UAshenOverheadCrushGASAbility()
{
	BaseCrushDamage = 900.0f;
	SoloAbsorptionDebtPenalty = 35.0f;
}

bool UAshenOverheadCrushGASAbility::ExecuteOverheadCrush(AActor* TargetActor, bool bWasSynchronizedParry)
{
	if (!TargetActor) return false;
	if (bWasSynchronizedParry)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenOverheadCrushGASAbility: Overhead Crush SYNCHRONIZED PARRIED! Zero debt accumulated!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenOverheadCrushGASAbility: Overhead Crush ABSORBED ALONE (Glass Shield)! Incurred +%.1f%% Debt Penalty!"),
			SoloAbsorptionDebtPenalty);
	}
	return true;
}
