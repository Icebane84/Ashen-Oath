// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenControllerFrictionMasterBridge.h"

UAshenControllerFrictionMasterBridge::UAshenControllerFrictionMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenControllerFrictionMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bFrictionBridgeActive = true;
}

void UAshenControllerFrictionMasterBridge::BroadcastStrugglePhaseResolved(EStrugglePhase Phase, bool bSuccess)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenControllerFrictionMasterBridge: Broadcasted Struggle Phase %d Resolved -> Success: %s"),
		static_cast<int32>(Phase), bSuccess ? TEXT("TRUE") : TEXT("FALSE"));
}
