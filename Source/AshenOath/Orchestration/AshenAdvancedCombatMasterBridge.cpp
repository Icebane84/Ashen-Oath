// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenAdvancedCombatMasterBridge.h"

UAshenAdvancedCombatMasterBridge::UAshenAdvancedCombatMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAdvancedCombatMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bCombatBridgeActive = true;
}

void UAshenAdvancedCombatMasterBridge::BroadcastAdvancedCombatPulse(FName EventName, float Magnitude)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAdvancedCombatMasterBridge: Combat Event '%s' (Magnitude: %.2f) broadcasted across domain adapters."),
		*EventName.ToString(), Magnitude);
}
