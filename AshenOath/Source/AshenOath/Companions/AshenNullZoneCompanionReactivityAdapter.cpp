// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenNullZoneCompanionReactivityAdapter.h"

UAshenNullZoneCompanionReactivityAdapter::UAshenNullZoneCompanionReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenNullZoneCompanionReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenNullZoneCompanionReactivityAdapter::NotifyCompanionNullZoneEntry(FName CompanionID, float ProximityRatio)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenNullZoneCompanionReactivityAdapter: %s entered Null Zone (Proximity: %.1f%%). Triggering caution posture."),
		*CompanionID.ToString(), ProximityRatio * 100.0f);
}
