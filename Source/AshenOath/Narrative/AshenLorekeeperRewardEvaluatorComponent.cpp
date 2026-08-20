// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLorekeeperRewardEvaluatorComponent.h"

UAshenLorekeeperRewardEvaluatorComponent::UAshenLorekeeperRewardEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLorekeeperRewardEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenLorekeeperRewardEvaluatorComponent::CalculatePoiseReward(int32 UnlockedOathswornCount) const
{
	// +2.5 Poise per unlocked Oathsworn record
	const float Bonus = static_cast<float>(UnlockedOathswornCount) * 2.5f;
	return Bonus;
}

float UAshenLorekeeperRewardEvaluatorComponent::CalculateResolveRegenBonus(int32 TotalReadEntries) const
{
	// +0.02 Resolve/sec per read codex entry (up to +0.50/s)
	const float Bonus = FMath::Min(0.50f, static_cast<float>(TotalReadEntries) * 0.02f);
	return Bonus;
}
