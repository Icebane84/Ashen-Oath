// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 441: Ashen Procedural Encounter Director Subsystem

#include "AshenProceduralEncounterDirectorSubsystem.h"

void UAshenProceduralEncounterDirectorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveThreatTier = 1;
	ActiveEnemyCount = 3;
	UE_LOG(LogTemp, Log, TEXT("UAshenProceduralEncounterDirectorSubsystem: Initialized — Procedural Encounter Director ONLINE."));
}

void UAshenProceduralEncounterDirectorSubsystem::ComposeDynamicEncounter(float CurrentSanity, float IntegrationDebt)
{
	if (CurrentSanity < 30.0f || IntegrationDebt > 60.0f)
	{
		ActiveThreatTier = 3;
		ActiveEnemyCount = 8; // High intensity nightmare manifestation wave
	}
	else if (CurrentSanity < 60.0f || IntegrationDebt > 30.0f)
	{
		ActiveThreatTier = 2;
		ActiveEnemyCount = 5;
	}
	else
	{
		ActiveThreatTier = 1;
		ActiveEnemyCount = 3;
	}

	OnEncounterComposed.Broadcast(ActiveThreatTier, ActiveEnemyCount);

	UE_LOG(LogTemp, Warning, TEXT("UAshenProceduralEncounterDirectorSubsystem: ENCOUNTER COMPOSED — Threat Tier %d (%d Enemies) [Sanity: %.1f, Debt: %.1f]."),
		ActiveThreatTier, ActiveEnemyCount, CurrentSanity, IntegrationDebt);
}
