// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenEliteInquisitionMasterBridge.h"

UAshenEliteInquisitionMasterBridge::UAshenEliteInquisitionMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenEliteInquisitionMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bEliteBridgeActive = true;
}

void UAshenEliteInquisitionMasterBridge::BroadcastEliteEventPulse(FName EliteID, uint8 StateEnum)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenEliteInquisitionMasterBridge: Elite Event for %s (State %d) broadcasted across domain adapters."),
		*EliteID.ToString(), StateEnum);
}
