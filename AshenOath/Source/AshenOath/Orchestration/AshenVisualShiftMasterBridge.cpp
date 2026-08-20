// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenVisualShiftMasterBridge.h"

UAshenVisualShiftMasterBridge::UAshenVisualShiftMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenVisualShiftMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bVisualShiftBridgeActive = true;
}

void UAshenVisualShiftMasterBridge::BroadcastVisualShiftPulse(float CorruptionIntensity, float DualityBlend)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenVisualShiftMasterBridge: Visual shift pulse (Corruption: %.2f, Blend: %.2f) broadcasted to all domain adapters."), CorruptionIntensity, DualityBlend);
}
