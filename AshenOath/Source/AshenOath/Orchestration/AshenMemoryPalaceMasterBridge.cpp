// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenMemoryPalaceMasterBridge.h"

UAshenMemoryPalaceMasterBridge::UAshenMemoryPalaceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMemoryPalaceMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bMemoryBridgeActive = true;
}

void UAshenMemoryPalaceMasterBridge::BroadcastLocusUnsealed(FName NodeID, EMemoryNodeType NodeType)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceMasterBridge: Broadcasted Locus Unsealed Event (Node: '%s', Type: %d)."),
		*NodeID.ToString(), static_cast<int32>(NodeType));
}

void UAshenMemoryPalaceMasterBridge::BroadcastBridgeReconstructed(FName BridgeID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceMasterBridge: Broadcasted Bridge Reconstructed Event (Bridge: '%s')."),
		*BridgeID.ToString());
}
