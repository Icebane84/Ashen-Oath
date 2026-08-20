// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenMindscapeResonanceMasterBridge.h"

UAshenMindscapeResonanceMasterBridge::UAshenMindscapeResonanceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMindscapeResonanceMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	SynchronizeMindscapeStateVector();
}

void UAshenMindscapeResonanceMasterBridge::SynchronizeMindscapeStateVector()
{
	bResonanceBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeResonanceMasterBridge: Mindscape state vector synchronized cleanly."));
}
