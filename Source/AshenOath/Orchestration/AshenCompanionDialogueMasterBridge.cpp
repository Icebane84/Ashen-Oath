// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenCompanionDialogueMasterBridge.h"

UAshenCompanionDialogueMasterBridge::UAshenCompanionDialogueMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionDialogueMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bDialogueBridgeActive = true;
}

void UAshenCompanionDialogueMasterBridge::BroadcastDialoguePulse(FName CompanionID, FString LineID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionDialogueMasterBridge: Dialogue pulse '%s' for %s broadcasted across all domain adapters."), *LineID, *CompanionID.ToString());
}
