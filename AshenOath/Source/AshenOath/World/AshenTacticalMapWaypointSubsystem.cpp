// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenTacticalMapWaypointSubsystem.h"

UAshenTacticalMapWaypointSubsystem::UAshenTacticalMapWaypointSubsystem()
{
	CurrentSanctuaryId = TEXT("Waypoint_Hearth_01");

	FTacticalWaypointVector Hearth1;
	Hearth1.WaypointId = TEXT("Waypoint_Hearth_01");
	Hearth1.DisplayName = FText::FromString(TEXT("Gloomwood Sanctuary Hearth"));
	Hearth1.WorldLocation = FVector(0.0f, 0.0f, 100.0f);
	Hearth1.BeaconState = EWaypointBeaconState::AttunedSanctuary;
	Hearth1.Biome = EMapRegionBiome::GloomwoodForest;
	Hearth1.bIsHearthRestSite = true;
	RegisteredWaypoints.Add(Hearth1);
}

bool UAshenTacticalMapWaypointSubsystem::AttuneWaypoint(const FString& WaypointId)
{
	for (FTacticalWaypointVector& Waypoint : RegisteredWaypoints)
	{
		if (Waypoint.WaypointId == WaypointId)
		{
			Waypoint.BeaconState = EWaypointBeaconState::AttunedSanctuary;
			OnWaypointStateChanged.Broadcast(WaypointId, Waypoint.BeaconState);
			return true;
		}
	}
	return false;
}

bool UAshenTacticalMapWaypointSubsystem::ExecuteFastTravel(const FString& DestinationWaypointId)
{
	if (DestinationWaypointId == CurrentSanctuaryId)
	{
		return false; // Already here
	}

	for (const FTacticalWaypointVector& Waypoint : RegisteredWaypoints)
	{
		if (Waypoint.WaypointId == DestinationWaypointId && Waypoint.BeaconState == EWaypointBeaconState::AttunedSanctuary)
		{
			const FString PrevSanctuary = CurrentSanctuaryId;
			CurrentSanctuaryId = DestinationWaypointId;
			OnFastTravelInitiated.Broadcast(PrevSanctuary, DestinationWaypointId);
			return true;
		}
	}
	return false;
}

void UAshenTacticalMapWaypointSubsystem::UnveilFogAtLocation(const FVector& Location, float RadiusUU)
{
	const float SafeRadius = FMath::Clamp(RadiusUU, 100.0f, 5000.0f);
	OnFogOfWarUnveiled.Broadcast(Location, SafeRadius);
}
