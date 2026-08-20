// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenNullZoneMasterBridge.h"

UAshenNullZoneMasterBridge::UAshenNullZoneMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNullZoneMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bNullZoneBridgeActive = true;
}

void UAshenNullZoneMasterBridge::BroadcastNullZoneTransition(bool bEntered, float DrainRate)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenNullZoneMasterBridge: Broadcasted Null Zone %s (Drain Rate: %.2f/s)."),
		bEntered ? TEXT("ENTERED") : TEXT("EXITED"), DrainRate);
}
