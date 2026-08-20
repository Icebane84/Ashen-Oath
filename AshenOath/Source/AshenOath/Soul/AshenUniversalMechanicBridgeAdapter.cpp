// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 649: Ashen Universal Mechanic Bridge Adapter

#include "AshenUniversalMechanicBridgeAdapter.h"

void UAshenUniversalMechanicBridgeAdapter::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalUMBMappingsActive = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenUniversalMechanicBridgeAdapter: Initialized — Universal Mechanic Bridge Adapter ONLINE."));
}

void UAshenUniversalMechanicBridgeAdapter::MapUMBModelToSystem(FName UMBModelID, FName TargetSystem)
{
	if (UMBModelID.IsNone()) return;

	TotalUMBMappingsActive++;
	OnUMBMapped.Broadcast(UMBModelID, TargetSystem, true);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUniversalMechanicBridgeAdapter: UMB MODEL MAPPED -> '%s' ==> '%s' (Total Active Mappings: %d)."),
		*UMBModelID.ToString(), *TargetSystem.ToString(), TotalUMBMappingsActive);
}
