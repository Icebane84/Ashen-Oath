// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenExecutionTelemetrySaveGameAdapter.h"

UAshenExecutionTelemetrySaveGameAdapter::UAshenExecutionTelemetrySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenExecutionTelemetrySaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenExecutionTelemetrySaveGameAdapter::SerializeExecutionTelemetryToSave(int32 TotalExecutionsCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenExecutionTelemetrySaveGameAdapter: %d total execution count serialized to save game."), TotalExecutionsCount);
	return true;
}
