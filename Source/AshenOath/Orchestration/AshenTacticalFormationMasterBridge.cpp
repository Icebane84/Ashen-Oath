// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Orchestration/AshenTacticalFormationMasterBridge.h"

UAshenTacticalFormationMasterBridge::UAshenTacticalFormationMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTacticalFormationMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	SynchronizeFormationStateVector();
}

void UAshenTacticalFormationMasterBridge::SynchronizeFormationStateVector()
{
	bFormationBridgeActive = true;
	UE_LOG(LogTemp, Log, TEXT("UAshenTacticalFormationMasterBridge: Tactical formation state synchronized with SoulState vector."));
}
