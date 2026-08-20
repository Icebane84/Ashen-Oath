// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenAlchemicalMasterBridge.h"

UAshenAlchemicalMasterBridge::UAshenAlchemicalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAlchemicalMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bAlchemicalBridgeActive = true;
}

void UAshenAlchemicalMasterBridge::BroadcastRecipeCrafted(EAlchemicalItemType ItemType, int32 Quantity)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalMasterBridge: Broadcasted Recipe Crafted (Item: %d, Qty: %d)."),
		static_cast<int32>(ItemType), Quantity);
}

void UAshenAlchemicalMasterBridge::BroadcastTripwireTriggered(const FVector& TrapLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalMasterBridge: Broadcasted Tripwire Triggered at %s."), *TrapLocation.ToString());
}
