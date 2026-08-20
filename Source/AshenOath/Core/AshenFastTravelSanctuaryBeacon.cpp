// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 211: Ashen Fast Travel Sanctuary Beacon Component

#include "AshenFastTravelSanctuaryBeacon.h"
#include "AshenFastTravelSubsystem.h"
#include "Engine/World.h"

UAshenFastTravelSanctuaryBeacon::UAshenFastTravelSanctuaryBeacon()
{
	PrimaryComponentTick.bCanEverTick = false;
	SanctuaryID = FName("Sanctuary_Default");
	bIsActivated = false;
}

void UAshenFastTravelSanctuaryBeacon::BeginPlay()
{
	Super::BeginPlay();

	// Register with subsystem
	if (GetWorld() && GetOwner())
	{
		UAshenFastTravelSubsystem* TravelSub = GetWorld()->GetSubsystem<UAshenFastTravelSubsystem>();
		if (TravelSub)
		{
			TravelSub->RegisterSanctuary(SanctuaryID, GetOwner()->GetActorLocation(), bIsActivated);
		}
	}
}

void UAshenFastTravelSanctuaryBeacon::ActivateBeacon()
{
	if (bIsActivated) return;

	bIsActivated = true;
	const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;

	if (GetWorld())
	{
		UAshenFastTravelSubsystem* TravelSub = GetWorld()->GetSubsystem<UAshenFastTravelSubsystem>();
		if (TravelSub)
		{
			TravelSub->UnlockSanctuary(SanctuaryID);
		}
	}

	OnBeaconActivated.Broadcast(SanctuaryID, Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFastTravelSanctuaryBeacon: Sanctuary Beacon '%s' ACTIVATED at (%.0f, %.0f, %.0f)."),
		*SanctuaryID.ToString(), Location.X, Location.Y, Location.Z);
}
