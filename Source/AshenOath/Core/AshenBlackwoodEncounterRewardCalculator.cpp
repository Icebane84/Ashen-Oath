// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 764: Ashen Blackwood Encounter Reward Calculator

#include "AshenBlackwoodEncounterRewardCalculator.h"

void UAshenBlackwoodEncounterRewardCalculator::CalculateEncounterRewards(float ClearTimeSeconds, float RemainingPartyHealthPercent)
{
	const float BaseBonus = 500.0f;
	const float TimeBonus = FMath::Clamp(180.0f - ClearTimeSeconds, 0.0f, 100.0f) * 2.0f;
	const float HealthBonus = RemainingPartyHealthPercent * 3.0f;

	const float TotalSanctuaryResources = BaseBonus + TimeBonus + HealthBonus;
	const float WillpowerEXP = TotalSanctuaryResources * 0.5f;

	OnRewardCalculated.Broadcast(TotalSanctuaryResources, WillpowerEXP);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBlackwoodEncounterRewardCalculator: ENCOUNTER REWARDS CALCULATED -> Sanctuary Resources: +%.0f | Willpower EXP: +%.0f."),
		TotalSanctuaryResources, WillpowerEXP);
}
