// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenCompanionFatigueMasterBridge.h"

UAshenCompanionFatigueMasterBridge::UAshenCompanionFatigueMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionFatigueMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bCompanionBridgeActive = true;
}

void UAshenCompanionFatigueMasterBridge::BroadcastResonanceSyncPulse(bool bSyncAchieved, float DamageMultiplier)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionFatigueMasterBridge: Broadcasted Resonance Sync Event (%s, Multiplier: %.2fx)."),
		bSyncAchieved ? TEXT("ACTIVE") : TEXT("INACTIVE"), DamageMultiplier);
}
