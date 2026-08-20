// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 478: Ashen Boss Arena Environmental Script Subsystem

#include "AshenBossArenaEnvironmentalScriptSubsystem.h"

void UAshenBossArenaEnvironmentalScriptSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenBossArenaEnvironmentalScriptSubsystem: Initialized — Boss Arena Environmental Script Subsystem ONLINE."));
}

void UAshenBossArenaEnvironmentalScriptSubsystem::TriggerArenaPhaseScript(FName ArenaID, int32 PhaseIndex)
{
	if (ArenaID.IsNone()) return;

	OnArenaStateChanged.Broadcast(ArenaID, PhaseIndex);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBossArenaEnvironmentalScriptSubsystem: BOSS ARENA SCRIPT TRIGGERED -> Arena '%s' [Phase %d]."),
		*ArenaID.ToString(), PhaseIndex);
}
