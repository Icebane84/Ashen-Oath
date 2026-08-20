// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionSliceStateAdapterComponent.h"

UAshenCompanionSliceStateAdapterComponent::UAshenCompanionSliceStateAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionSliceStateAdapterComponent::SubmitRelationalImprint(FName CompanionID, float FrictionSeverity)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionSliceStateAdapterComponent: Companion slice submitting imprint for %s (Friction: %.2f)"),
		*CompanionID.ToString(), FrictionSeverity);
}

void UAshenCompanionSliceStateAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	GarrettFormationDistance = FMath::Clamp(1.0f + (NewState.Isolation * 1.5f) - (NewState.GarrettTrust * 0.5f), 0.5f, 3.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionSliceStateAdapterComponent: Garrett formation distance scalar updated to %.2f"), GarrettFormationDistance);
}
