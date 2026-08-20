// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettTacticalCoverConvergerComponent.h"

UAshenGarrettTacticalCoverConvergerComponent::UAshenGarrettTacticalCoverConvergerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FVector UAshenGarrettTacticalCoverConvergerComponent::CalculateTargetCoverLocation(const FVector& KaelenLocation, const FVector& NominalCover, float GarrettTrust)
{
	float LerpAlpha = FMath::Clamp(GarrettTrust, 0.2f, 0.9f);
	FVector ConvergedLocation = FMath::Lerp(NominalCover, KaelenLocation, LerpAlpha * 0.4f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTacticalCoverConvergerComponent: Calculated converged cover location for Garrett (Trust: %.2f)"), GarrettTrust);
	return ConvergedLocation;
}
