// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 579: Ashen Shadowfen Encounter Director Subsystem

#include "AshenShadowfenEncounterDirectorSubsystem.h"

void UAshenShadowfenEncounterDirectorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalEncountersDispatched = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenShadowfenEncounterDirectorSubsystem: Initialized — Shadowfen Encounter Director ONLINE."));
}

void UAshenShadowfenEncounterDirectorSubsystem::DispatchShadowfenEncounter(FName EncounterID, int32 ThreatLevel)
{
	if (EncounterID.IsNone()) return;

	TotalEncountersDispatched++;
	OnEncounterSpawned.Broadcast(EncounterID, ThreatLevel);

	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowfenEncounterDirectorSubsystem: SHADOWFEN ENCOUNTER DISPATCHED -> '%s' (Threat Level: %d | Total: %d)."),
		*EncounterID.ToString(), ThreatLevel, TotalEncountersDispatched);
}
