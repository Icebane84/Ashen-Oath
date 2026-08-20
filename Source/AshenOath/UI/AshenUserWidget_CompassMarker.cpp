// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 204: Ashen Compass Marker UMG Widget

#include "AshenUserWidget_CompassMarker.h"

void UAshenUserWidget_CompassMarker::SetupMarker(FName MarkerID, EAshenCompassMarkerType MarkerType, FVector WorldLocation)
{
	CurrentMarkerID = MarkerID;
	CurrentMarkerType = MarkerType;
	CachedWorldLocation = WorldLocation;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CompassMarker: Marker '%s' setup (Type %d) at (%.0f, %.0f, %.0f)."),
		*MarkerID.ToString(), (int32)MarkerType, WorldLocation.X, WorldLocation.Y, WorldLocation.Z);
}

void UAshenUserWidget_CompassMarker::UpdateScreenOffset(float NormalizedOffset, float DistanceMeters)
{
	CurrentNormalizedOffset = NormalizedOffset;
	CurrentDistanceMeters = DistanceMeters;
}
