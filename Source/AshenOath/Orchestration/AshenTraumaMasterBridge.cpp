// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenTraumaMasterBridge.h"

UAshenTraumaMasterBridge::UAshenTraumaMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTraumaMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bTraumaBridgeActive = true;
}

void UAshenTraumaMasterBridge::BroadcastCircuitBreakerTripped(FName TargetHero, float UtilityScore)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenTraumaMasterBridge: Broadcasted Circuit Breaker Tripped on %s (Utility: %.2f)!"),
		*TargetHero.ToString(), UtilityScore);
}

void UAshenTraumaMasterBridge::BroadcastForcedMindscapeTriggered()
{
	UE_LOG(LogTemp, Error, TEXT("UAshenTraumaMasterBridge: Broadcasted Forced Mindscape Triggered at 100%% Debt!"));
}
