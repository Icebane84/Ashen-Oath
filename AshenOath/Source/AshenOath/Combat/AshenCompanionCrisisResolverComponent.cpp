// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCompanionCrisisResolverComponent.h"

UAshenCompanionCrisisResolverComponent::UAshenCompanionCrisisResolverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentContext.CrisisState = ECompanionCrisisState::None;
}

FCompanionCrisisContext UAshenCompanionCrisisResolverComponent::OpenCrisisWindow(
	FName CompanionName,
	float WindowSeconds)
{
	CurrentContext.PinnedCompanionName = CompanionName;
	CurrentContext.CrisisState = ECompanionCrisisState::PinnedInExecution;
	CurrentContext.RemainingDecisionWindowSeconds = WindowSeconds;
	CurrentContext.TrustRewardOnRescue = 0.20f;

	return CurrentContext;
}

bool UAshenCompanionCrisisResolverComponent::ResolveCrisis(
	bool bIntervenedViaTransference,
	ECompanionCrisisState& OutOutcome,
	float& OutTrustDelta)
{
	if (CurrentContext.CrisisState != ECompanionCrisisState::PinnedInExecution)
	{
		return false;
	}

	if (bIntervenedViaTransference)
	{
		CurrentContext.CrisisState = ECompanionCrisisState::RescuedByTransference;
		OutOutcome = ECompanionCrisisState::RescuedByTransference;
		OutTrustDelta = CurrentContext.TrustRewardOnRescue; // +0.20
	}
	else
	{
		CurrentContext.CrisisState = ECompanionCrisisState::WoundedFallback;
		OutOutcome = ECompanionCrisisState::WoundedFallback;
		OutTrustDelta = -0.10f; // Erosion
	}

	CurrentContext.RemainingDecisionWindowSeconds = 0.0f;
	return true;
}
