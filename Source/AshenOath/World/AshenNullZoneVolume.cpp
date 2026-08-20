// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenNullZoneVolume.h"

AAshenNullZoneVolume::AAshenNullZoneVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	NullZoneRadius = 1500.0f;
	DrainRatePerSecond = 0.05f;
	bIsPlayerInside = false;
}
void AAshenNullZoneVolume::BeginPlay() { Super::BeginPlay(); }

float AAshenNullZoneVolume::CalculateProximityRatio(FVector PlayerLocation) const
{
	const float Distance = FVector::Dist(GetActorLocation(), PlayerLocation);
	if (Distance > NullZoneRadius) return 0.0f;
	return FMath::Clamp(1.0f - (Distance / NullZoneRadius), 0.0f, 1.0f);
}
