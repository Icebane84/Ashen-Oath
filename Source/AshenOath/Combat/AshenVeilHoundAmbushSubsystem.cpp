// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 566: Ashen Veil Hound Ambush Subsystem

#include "AshenVeilHoundAmbushSubsystem.h"

void UAshenVeilHoundAmbushSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAmbushesSpawned = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenVeilHoundAmbushSubsystem: Initialized — Veil Hound Ambush Engine ONLINE."));
}

void UAshenVeilHoundAmbushSubsystem::TriggerVeilHoundAmbushPack(int32 PackCount, float Intensity)
{
	TotalAmbushesSpawned += PackCount;
	OnAmbushTriggered.Broadcast(PackCount, Intensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenVeilHoundAmbushSubsystem: VEIL HOUND AMBUSH TRIGGERED -> Pack Count: %d | Intensity: %.1f (Total: %d)."),
		PackCount, Intensity, TotalAmbushesSpawned);
}
