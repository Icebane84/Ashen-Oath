// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenUnchainedVitalLeechComponent.h"

UAshenUnchainedVitalLeechComponent::UAshenUnchainedVitalLeechComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CompanionVitalLeechPercentage = 0.15f;
}
void UAshenUnchainedVitalLeechComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenUnchainedVitalLeechComponent::ProcessUnchainedCleaveHit(AActor* HitTarget, bool bIsCompanion, float& OutVitalDrained)
{
	if (!HitTarget) return false;

	if (bIsCompanion)
	{
		OutVitalDrained = CompanionVitalLeechPercentage * 100.0f; // 15 points
		UE_LOG(LogTemp, Error, TEXT("UAshenUnchainedVitalLeechComponent: FRIENDLY-FIRE CLEAVE on %s! Leeched %.1f%% vital reserves!"),
			*HitTarget->GetName(), CompanionVitalLeechPercentage * 100.0f);
		return true;
	}

	OutVitalDrained = 0.0f;
	return false;
}
