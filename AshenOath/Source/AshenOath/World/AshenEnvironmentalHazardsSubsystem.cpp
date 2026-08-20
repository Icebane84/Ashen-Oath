// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 228: Ashen Environmental Hazards Subsystem

#include "AshenEnvironmentalHazardsSubsystem.h"

void UAshenEnvironmentalHazardsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveHazards.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenEnvironmentalHazardsSubsystem: Initialized — Hazard Tracking Network active."));
}

void UAshenEnvironmentalHazardsSubsystem::RegisterHazard(FName HazardID, EAshenHazardType HazardType, FVector Location)
{
	if (HazardID.IsNone() || ActiveHazards.Contains(HazardID)) return;

	FHazardRecord Record;
	Record.Type = HazardType;
	Record.Location = Location;

	ActiveHazards.Add(HazardID, Record);
	OnHazardRegistered.Broadcast(HazardID, HazardType, Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEnvironmentalHazardsSubsystem: Registered hazard '%s' (Type %d) at (%.0f, %.0f, %.0f). Total: %d."),
		*HazardID.ToString(), (int32)HazardType, Location.X, Location.Y, Location.Z, ActiveHazards.Num());
}

void UAshenEnvironmentalHazardsSubsystem::DeregisterHazard(FName HazardID)
{
	if (ActiveHazards.Remove(HazardID) > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenEnvironmentalHazardsSubsystem: Deregistered hazard '%s'."), *HazardID.ToString());
	}
}
