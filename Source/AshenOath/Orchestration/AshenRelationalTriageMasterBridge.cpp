// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenRelationalTriageMasterBridge.h"

UAshenRelationalTriageMasterBridge::UAshenRelationalTriageMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRelationalTriageMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bRelationalBridgeActive = true;
}

void UAshenRelationalTriageMasterBridge::BroadcastStanceCompiled(ECompiledRelationalStance Stance)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenRelationalTriageMasterBridge: Broadcasted Compiled Relational Stance -> %d"),
		static_cast<int32>(Stance));
}
