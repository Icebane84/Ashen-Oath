// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettTripleComboFlankAdapterComponent.h"

UAshenGarrettTripleComboFlankAdapterComponent::UAshenGarrettTripleComboFlankAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettTripleComboFlankAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	GarrettTrustLevel = NewState.GarrettTrust;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTripleComboFlankAdapterComponent: Garrett trust level set to %.2f"), GarrettTrustLevel);
}

FVector UAshenGarrettTripleComboFlankAdapterComponent::ComputeFlankPosition(const FVector& TargetLocation, const FVector& KaelenLocation) const
{
	FVector Dir = (TargetLocation - KaelenLocation).GetSafeNormal();
	FVector OrthoDir = FVector::CrossProduct(Dir, FVector::UpVector);
	return TargetLocation + (OrthoDir * 250.0f * (1.0f / FMath::Max(GarrettTrustLevel, 0.1f)));
}
