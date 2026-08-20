// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenAlchemicalEcologyMasterBridge.h"

UAshenAlchemicalEcologyMasterBridge::UAshenAlchemicalEcologyMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAlchemicalEcologyMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bEcologyBridgeActive = true;
}

void UAshenAlchemicalEcologyMasterBridge::BroadcastAlchemicalEventPulse(FName EventName, float Level)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalEcologyMasterBridge: Alchemical Event '%s' (Level: %.2f) broadcasted across domain adapters."),
		*EventName.ToString(), Level);
}
