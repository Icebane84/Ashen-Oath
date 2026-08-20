// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenWhiteFlameMasterBridge.h"

UAshenWhiteFlameMasterBridge::UAshenWhiteFlameMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWhiteFlameMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bWhiteFlameBridgeActive = true;
}

void UAshenWhiteFlameMasterBridge::BroadcastWhiteFlameInvoked(float ClearedDebt)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameMasterBridge: Broadcasted White Flame Resolution Invoked (Cleared %.1f Debt)!"),
		ClearedDebt);
}
