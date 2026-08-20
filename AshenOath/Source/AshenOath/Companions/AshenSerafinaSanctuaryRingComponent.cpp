// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenSerafinaSanctuaryRingComponent.h"

UAshenSerafinaSanctuaryRingComponent::UAshenSerafinaSanctuaryRingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaSanctuaryRingComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenSerafinaSanctuaryRingComponent::ManifestSanctuaryRing(FVector GroundLocation)
{
	if (OnSanctuaryRingDeployed.IsBound())
	{
		OnSanctuaryRingDeployed.Broadcast(GroundLocation, SanctuaryRadius);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSanctuaryRingComponent: Consecrated sanctuary ring manifested at (%f, %f, %f) with radius %.0fuu"),
		GroundLocation.X, GroundLocation.Y, GroundLocation.Z, SanctuaryRadius);
	return true;
}
