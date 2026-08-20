// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenSerafinaMasterBridge.h"

UAshenSerafinaMasterBridge::UAshenSerafinaMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bSerafinaBridgeActive = true;
}

void UAshenSerafinaMasterBridge::BroadcastTransferencePulse(float HealedAmount, float BurnoutToll)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaMasterBridge: Transference Pulse (Healed: %.1f | Toll: %.1f) broadcasted across all domain adapters."),
		HealedAmount, BurnoutToll);
}
