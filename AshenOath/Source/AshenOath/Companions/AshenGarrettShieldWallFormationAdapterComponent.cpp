// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettShieldWallFormationAdapterComponent.h"

UAshenGarrettShieldWallFormationAdapterComponent::UAshenGarrettShieldWallFormationAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FVector UAshenGarrettShieldWallFormationAdapterComponent::CalculateShieldWallOffset(const FVector& KaelenLocation, const FVector& KaelenForwardVector, float GarrettTrust)
{
	float ForwardDistance = 150.0f + (GarrettTrust * 100.0f);
	FVector ShieldWallLocation = KaelenLocation + (KaelenForwardVector * ForwardDistance);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettShieldWallFormationAdapterComponent: Calculated Garrett shield wall location at forward distance %.1f"), ForwardDistance);
	return ShieldWallLocation;
}
