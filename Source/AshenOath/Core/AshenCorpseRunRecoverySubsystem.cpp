// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 348: Ashen Corpse Run Recovery Subsystem

#include "AshenCorpseRunRecoverySubsystem.h"

void UAshenCorpseRunRecoverySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bHasActiveMarker = false;
	StoredDroppedEmbers = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCorpseRunRecoverySubsystem: Initialized — Corpse Run Recovery Subsystem active."));
}

void UAshenCorpseRunRecoverySubsystem::SpawnCorpseRunMarker(FVector DeathLocation, float EmbersLost)
{
	CorpseLocation = DeathLocation;
	StoredDroppedEmbers = EmbersLost;
	bHasActiveMarker = true;

	OnCorpseMarkerStateChanged.Broadcast(DeathLocation, EmbersLost);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCorpseRunRecoverySubsystem: CORPSE RUN MARKER SPAWNED at %s (Dropped Embers: %.0f)."),
		*DeathLocation.ToString(), EmbersLost);
}

float UAshenCorpseRunRecoverySubsystem::RecoverCorpseRunEmbers()
{
	if (!bHasActiveMarker) return 0.0f;

	const float Recovered = StoredDroppedEmbers;
	StoredDroppedEmbers = 0.0f;
	bHasActiveMarker = false;

	OnCorpseMarkerStateChanged.Broadcast(FVector::ZeroVector, 0.0f);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCorpseRunRecoverySubsystem: CORPSE RUN RECOVERED! (+%.0f Embers)."), Recovered);

	return Recovered;
}
