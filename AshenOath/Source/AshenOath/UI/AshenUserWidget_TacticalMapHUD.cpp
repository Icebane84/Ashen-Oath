// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_TacticalMapHUD.h"

UAshenUserWidget_TacticalMapHUD::UAshenUserWidget_TacticalMapHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ActiveSelectedWaypointId = TEXT("Waypoint_Hearth_01");
}

void UAshenUserWidget_TacticalMapHUD::UpdateMapHUD(
	const TArray<FTacticalWaypointVector>& Waypoints,
	const FString& SelectedWaypointId)
{
	DisplayedWaypoints = Waypoints;
	ActiveSelectedWaypointId = SelectedWaypointId;
}
