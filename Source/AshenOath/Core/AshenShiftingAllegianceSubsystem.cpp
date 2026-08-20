// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 376: Ashen Shifting Allegiance Subsystem

#include "AshenShiftingAllegianceSubsystem.h"

void UAshenShiftingAllegianceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TerritoryControlMap.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenShiftingAllegianceSubsystem: Initialized — Territorial Allegiance War Map ONLINE."));
}

void UAshenShiftingAllegianceSubsystem::ShiftTerritoryControl(FName RegionID, FName NewControllingFactionID)
{
	if (RegionID.IsNone() || NewControllingFactionID.IsNone()) return;

	TerritoryControlMap.Add(RegionID, NewControllingFactionID);
	OnTerritoryControlShifted.Broadcast(RegionID, NewControllingFactionID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenShiftingAllegianceSubsystem: TERRITORY CONTROL SHIFTED — Region '%s' now controlled by '%s'."),
		*RegionID.ToString(), *NewControllingFactionID.ToString());
}

FName UAshenShiftingAllegianceSubsystem::GetControllingFaction(FName RegionID) const
{
	return TerritoryControlMap.Contains(RegionID) ? TerritoryControlMap[RegionID] : NAME_None;
}
