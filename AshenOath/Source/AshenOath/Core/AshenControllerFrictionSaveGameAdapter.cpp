// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenControllerFrictionSaveGameAdapter.h"

UAshenControllerFrictionSaveGameAdapter::UAshenControllerFrictionSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenControllerFrictionSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenControllerFrictionSaveGameAdapter::SaveFrictionTelemetry(int32 SuccessfulLockHolds, int32 InterceptCount, int32 ReclamationCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenControllerFrictionSaveGameAdapter: Saved Friction Telemetry -> %d Locks Held, %d Intercepts, %d Reclamations"),
		SuccessfulLockHolds, InterceptCount, ReclamationCount);
	return true;
}
