// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 396: Ashen Nightmare Labyrinth Boss Subsystem

#include "AshenNightmareLabyrinthBossSubsystem.h"

void UAshenNightmareLabyrinthBossSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareLabyrinthBossSubsystem: Initialized — Nightmare Labyrinth Boss Arena ONLINE."));
}

void UAshenNightmareLabyrinthBossSubsystem::DefeatNightmareBoss(FName BossID)
{
	OnNightmareBossDefeated.Broadcast(BossID, true);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNightmareLabyrinthBossSubsystem: NIGHTMARE BOSS '%s' DEFEATED — Trauma Conquered! Skill Evolution Unlocked."),
		*BossID.ToString());
}
