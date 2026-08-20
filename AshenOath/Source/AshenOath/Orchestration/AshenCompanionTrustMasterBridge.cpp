// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenCompanionTrustMasterBridge.h"

UAshenCompanionTrustMasterBridge::UAshenCompanionTrustMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionTrustMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bTrustBridgeActive = true;
}

void UAshenCompanionTrustMasterBridge::BroadcastTrustUpdatePulse(float GarrettTrust, float SerafinaTrust)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionTrustMasterBridge: Trust update pulse broadcasted across domain adapters (Garrett: %.2f, Serafina: %.2f)"), GarrettTrust, SerafinaTrust);
}
