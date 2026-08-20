// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenCognitiveAIMasterBridge.h"

UAshenCognitiveAIMasterBridge::UAshenCognitiveAIMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCognitiveAIMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	BroadcastCognitiveStatePulse();
}

void UAshenCognitiveAIMasterBridge::BroadcastCognitiveStatePulse()
{
	bCognitiveBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenCognitiveAIMasterBridge: Cognitive AI state pulse broadcasted across domain adapters."));
}
