// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenSomaticMasterBridge.h"

UAshenSomaticMasterBridge::UAshenSomaticMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bSomaticBridgeActive = true;
}

void UAshenSomaticMasterBridge::BroadcastSomaticPulse(FName ParameterName, float Value)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticMasterBridge: Somatic Event '%s' (Value: %.2f) broadcasted across domain adapters."),
		*ParameterName.ToString(), Value);
}
