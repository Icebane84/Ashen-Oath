// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenCampfireRestMasterBridge.h"

UAshenCampfireRestMasterBridge::UAshenCampfireRestMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCampfireRestMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bCampfireBridgeActive = true;
}

void UAshenCampfireRestMasterBridge::BroadcastCampfireRestPulse(FName CampfireID, uint8 StateEnum)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCampfireRestMasterBridge: Campfire Event for %s (State %d) broadcasted across domain adapters."),
		*CampfireID.ToString(), StateEnum);
}
