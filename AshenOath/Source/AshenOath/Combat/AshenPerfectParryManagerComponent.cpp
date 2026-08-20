// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPerfectParryManagerComponent.h"

UAshenPerfectParryManagerComponent::UAshenPerfectParryManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PerfectParryWindowDuration = 0.20f;
	SanityRestoredOnParry = 15.0f;
}
void UAshenPerfectParryManagerComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenPerfectParryManagerComponent::EvaluateParryTiming(float TimeSinceGuardInitiated, float& OutSanityRestored)
{
	const bool bIsPerfectParry = (TimeSinceGuardInitiated >= 0.0f) && (TimeSinceGuardInitiated <= PerfectParryWindowDuration);
	if (bIsPerfectParry)
	{
		OutSanityRestored = SanityRestoredOnParry;
		UE_LOG(LogTemp, Warning, TEXT("UAshenPerfectParryManagerComponent: PERFECT PARRY TRIGGERED! (Timing: %.3fs <= %.2fs, Restored +%.1f Sanity)."),
			TimeSinceGuardInitiated, PerfectParryWindowDuration, OutSanityRestored);
	}
	else
	{
		OutSanityRestored = 0.0f;
	}

	return bIsPerfectParry;
}
