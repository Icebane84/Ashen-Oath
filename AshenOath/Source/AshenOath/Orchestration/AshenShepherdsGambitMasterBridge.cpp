// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenShepherdsGambitMasterBridge.h"

UAshenShepherdsGambitMasterBridge::UAshenShepherdsGambitMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenShepherdsGambitMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bGambitBridgeActive = true;
}

void UAshenShepherdsGambitMasterBridge::BroadcastContainmentStatus(EContainmentState State)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenShepherdsGambitMasterBridge: Broadcasted Containment Status -> %d"),
		static_cast<int32>(State));
}
