// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenSoulRehabilitationMasterBridge.h"

UAshenSoulRehabilitationMasterBridge::UAshenSoulRehabilitationMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSoulRehabilitationMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bRehabilitationBridgeActive = true;
}

void UAshenSoulRehabilitationMasterBridge::BroadcastRehabilitationPulse(float IdentityPurityScore)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSoulRehabilitationMasterBridge: Rehabilitation pulse (Purity: %.2f) broadcasted across all domain adapters."), IdentityPurityScore);
}
