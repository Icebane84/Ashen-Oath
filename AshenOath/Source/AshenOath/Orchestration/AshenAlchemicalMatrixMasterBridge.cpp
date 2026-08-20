// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenAlchemicalMatrixMasterBridge.h"

UAshenAlchemicalMatrixMasterBridge::UAshenAlchemicalMatrixMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenAlchemicalMatrixMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bAlchemicalBridgeActive = true;
}

void UAshenAlchemicalMatrixMasterBridge::BroadcastMatrixDeployed(EAlchemicalMatrixType Type)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalMatrixMasterBridge: Broadcasted Alchemical Matrix %d Deployed!"),
		static_cast<int32>(Type));
}
