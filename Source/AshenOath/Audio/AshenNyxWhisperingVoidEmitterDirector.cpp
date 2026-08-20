// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 737: Ashen Nyx Whispering Void Emitter Director

#include "AshenNyxWhisperingVoidEmitterDirector.h"

void UAshenNyxWhisperingVoidEmitterDirector::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalWhispersSpawned = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenNyxWhisperingVoidEmitterDirector: Initialized — Nyx Whispering Void Emitter Director ONLINE."));
}

void UAshenNyxWhisperingVoidEmitterDirector::SpawnLocalizedWhisper(FVector Location, float Intensity)
{
	TotalWhispersSpawned++;
	OnWhisperSpawned.Broadcast(Location, Intensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNyxWhisperingVoidEmitterDirector: LOCALIZED WHISPER SPAWNED -> Location: (%s) | Intensity: %.2f (Total: %d)."),
		*Location.ToString(), Intensity, TotalWhispersSpawned);
}
