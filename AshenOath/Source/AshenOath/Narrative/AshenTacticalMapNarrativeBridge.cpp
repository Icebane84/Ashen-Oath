// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenTacticalMapNarrativeBridge.h"

UAshenTacticalMapNarrativeBridge::UAshenTacticalMapNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenTacticalMapNarrativeBridge::FormatTravelBark(
	EWaypointBeaconState BeaconState,
	ETravelHazardType HazardType) const
{
	if (HazardType == ETravelHazardType::RoadsideAmbush)
	{
		return FText::FromString(TEXT("[Garrett]: 'AMBUSH! Out of the tree line—weapons up!'"));
	}
	else if (HazardType == ETravelHazardType::BlizzardCollapse)
	{
		return FText::FromString(TEXT("[Serafina]: 'The pass is snowed in! Find shelter before we freeze!'"));
	}

	switch (BeaconState)
	{
	case EWaypointBeaconState::AttunedSanctuary:
		return FText::FromString(TEXT("[Serafina]: 'The hearth flame is rekindled. We have an anchor in these ruins.'"));
	case EWaypointBeaconState::DiscoveredBeacon:
		return FText::FromString(TEXT("[Kaelen]: 'An old beacon. Bring the White Flame to light it.'"));
	case EWaypointBeaconState::ContestedCorrupted:
		return FText::FromString(TEXT("[Garrett]: 'Corrupted creatures surrounding the brazier. Clear them out.'"));
	case EWaypointBeaconState::UndiscoveredShadow:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Check the map. The fog is thick ahead.'"));
	}
}
