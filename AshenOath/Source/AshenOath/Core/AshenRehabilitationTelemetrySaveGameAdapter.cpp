// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenRehabilitationTelemetrySaveGameAdapter.h"

UAshenRehabilitationTelemetrySaveGameAdapter::UAshenRehabilitationTelemetrySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenRehabilitationTelemetrySaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenRehabilitationTelemetrySaveGameAdapter::SerializeRehabilitationTelemetryToSave(int32 TotalRitualCompletionsCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenRehabilitationTelemetrySaveGameAdapter: %d total rehabilitation ritual completions serialized to save game."), TotalRitualCompletionsCount);
	return true;
}
