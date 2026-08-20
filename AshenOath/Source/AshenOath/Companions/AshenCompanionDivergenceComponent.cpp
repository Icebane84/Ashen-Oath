// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionDivergenceComponent.h"

UAshenCompanionDivergenceComponent::UAshenCompanionDivergenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	FollowOffset = 300.0f;
}
void UAshenCompanionDivergenceComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenCompanionDivergenceComponent::EvaluateNavigationOffset(FName CompanionID, float CompanionTrust, bool bIsIsolated)
{
	if (bIsIsolated || CompanionTrust < 0.35f)
	{
		FollowOffset = (CompanionID == FName(TEXT("Garrett"))) ? 800.0f : 550.0f;
	}
	else
	{
		FollowOffset = (CompanionID == FName(TEXT("Garrett"))) ? 350.0f : 250.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionDivergenceComponent: Navigation follow offset for %s set to %.1fuu (Trust: %.2f, Isolated: %s)."),
		*CompanionID.ToString(), FollowOffset, CompanionTrust, bIsIsolated ? TEXT("TRUE") : TEXT("FALSE"));
	return FollowOffset;
}
