// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenSanctifiedGroundZoneActor.h"

AAshenSanctifiedGroundZoneActor::AAshenSanctifiedGroundZoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
	ZoneData.RadiusUnits = 800.0f;
	ZoneData.StaminaBuffMultiplier = 1.20f;
}
void AAshenSanctifiedGroundZoneActor::BeginPlay() { Super::BeginPlay(); }

void AAshenSanctifiedGroundZoneActor::InitializeZone(FVector Center, float Radius)
{
	ZoneData.CenterLocation = Center;
	ZoneData.RadiusUnits = Radius;
	UE_LOG(LogTemp, Warning, TEXT("AAshenSanctifiedGroundZoneActor: Consecrated Ground Zone Initialized at %s (Radius: %.1fuu, +20%% Stamina)!"),
		*Center.ToString(), Radius);
}
