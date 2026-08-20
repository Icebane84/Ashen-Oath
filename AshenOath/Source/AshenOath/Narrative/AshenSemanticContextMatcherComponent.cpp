// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenSemanticContextMatcherComponent.h"

UAshenSemanticContextMatcherComponent::UAshenSemanticContextMatcherComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenSemanticContextMatcherComponent::MatchesCrisisContext(
	const FCanonicalPromiseRecord& Promise,
	FGameplayTag CurrentCrisisTag,
	FName ActiveCompanion) const
{
	if (Promise.Status != EPromiseResolutionStatus::Active)
	{
		return false;
	}

	// Match companion target
	if (!Promise.TargetCompanionName.IsNone() && Promise.TargetCompanionName != ActiveCompanion)
	{
		return false;
	}

	// Match context tag hierarchy
	if (CurrentCrisisTag.MatchesTag(Promise.TriggerContextTag) || Promise.TriggerContextTag.MatchesTag(CurrentCrisisTag))
	{
		return true;
	}

	return false;
}
