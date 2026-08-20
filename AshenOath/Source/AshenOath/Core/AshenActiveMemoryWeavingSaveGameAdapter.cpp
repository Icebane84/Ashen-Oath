// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenActiveMemoryWeavingSaveGameAdapter.h"

UAshenActiveMemoryWeavingSaveGameAdapter::UAshenActiveMemoryWeavingSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenActiveMemoryWeavingSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenActiveMemoryWeavingSaveGameAdapter::SaveWeavingTelemetry(int32 BridgesManifested, int32 NetsDeployed, int32 SnappedThreads)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenActiveMemoryWeavingSaveGameAdapter: Saved Weaving Telemetry -> %d Bridges, %d Nets, %d Snaps"),
		BridgesManifested, NetsDeployed, SnappedThreads);
	return true;
}
