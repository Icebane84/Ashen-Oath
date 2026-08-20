// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 736: Ashen Memory Palace Graph Compiler Subsystem

#include "AshenMemoryPalaceGraphCompilerSubsystem.h"

void UAshenMemoryPalaceGraphCompilerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveGraphCoherence = 100.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceGraphCompilerSubsystem: Initialized — Memory Palace Graph Compiler Subsystem ONLINE."));
}

void UAshenMemoryPalaceGraphCompilerSubsystem::CompileMemoryConstellationGraph(int32 UnlockedNodesCount)
{
	ActiveGraphCoherence = FMath::Clamp(100.0f - (UnlockedNodesCount * 2.5f), 40.0f, 100.0f);
	OnMemoryGraphCompiled.Broadcast(UnlockedNodesCount, ActiveGraphCoherence);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryPalaceGraphCompilerSubsystem: CONSTELLATION GRAPH COMPILED -> Unlocked Nodes: %d | Graph Coherence: %.1f%%."),
		UnlockedNodesCount, ActiveGraphCoherence);
}
