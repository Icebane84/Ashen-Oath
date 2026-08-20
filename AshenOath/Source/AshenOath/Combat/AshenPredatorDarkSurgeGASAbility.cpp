// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPredatorDarkSurgeGASAbility.h"

UAshenPredatorDarkSurgeGASAbility::UAshenPredatorDarkSurgeGASAbility()
{
	DarkPowerDamageBonusRatio = 0.15f;
	SootStainPenalty = 5.0f;
}

bool UAshenPredatorDarkSurgeGASAbility::ExecuteDarkSurge(float& OutSootAdded)
{
	OutSootAdded = SootStainPenalty;
	UE_LOG(LogTemp, Warning, TEXT("UAshenPredatorDarkSurgeGASAbility: PREDATOR DARK SURGE EXECUTED (+%.1f%% Dark DMG, +%.1f Soot)!"),
		DarkPowerDamageBonusRatio * 100.0f, OutSootAdded);
	return true;
}
