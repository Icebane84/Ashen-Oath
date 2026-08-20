// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 391: Ashen Mindscape Dungeon Generation Subsystem

#include "AshenMindscapeDungeonGenerationSubsystem.h"

void UAshenMindscapeDungeonGenerationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveSeed = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeDungeonGenerationSubsystem: Initialized — Procedural Mindscape Seed Generator ONLINE."));
}

void UAshenMindscapeDungeonGenerationSubsystem::GenerateMindscapeDungeonLayout(int32 Seed, FName Theme)
{
	ActiveSeed = Seed;
	OnDungeonGenerated.Broadcast(Seed, Theme);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMindscapeDungeonGenerationSubsystem: MINDSCAPE DUNGEON GENERATED — Seed: %d, Theme: '%s'."),
		Seed, *Theme.ToString());
}
