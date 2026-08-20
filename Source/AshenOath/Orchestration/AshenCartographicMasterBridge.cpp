// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenCartographicMasterBridge.h"

UAshenCartographicMasterBridge::UAshenCartographicMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCartographicMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bCartographicBridgeActive = true;
}

void UAshenCartographicMasterBridge::BroadcastLandmarkInked(const FJournalMapPin& InkedPin)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCartographicMasterBridge: Broadcasted Landmark Inked: %s at %s"),
		*InkedPin.PinLabel, *InkedPin.WorldLocation.ToString());
}
