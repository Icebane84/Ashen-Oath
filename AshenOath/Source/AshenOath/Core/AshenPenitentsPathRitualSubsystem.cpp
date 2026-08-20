// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 339: Ashen Penitent's Path Ritual Subsystem

#include "AshenPenitentsPathRitualSubsystem.h"

void UAshenPenitentsPathRitualSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveRitualID = NAME_None;
	UE_LOG(LogTemp, Log, TEXT("UAshenPenitentsPathRitualSubsystem: Initialized — Penitent's Path Ritual Subsystem active."));
}

bool UAshenPenitentsPathRitualSubsystem::BeginPenitentRitual(FName RitualID)
{
	if (RitualID.IsNone()) return false;

	ActiveRitualID = RitualID;

	UE_LOG(LogTemp, Warning, TEXT("UAshenPenitentsPathRitualSubsystem: PENITENT RITUAL BEGUN — '%s' at Heartstone Crucible."),
		*RitualID.ToString());

	return true;
}

void UAshenPenitentsPathRitualSubsystem::CompletePenitentRitual(FName RitualID, bool bSuccess)
{
	OnPenitentRitualCompleted.Broadcast(RitualID, bSuccess);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPenitentsPathRitualSubsystem: PENITENT RITUAL '%s' FINISHED — Atonement: %s."),
		*RitualID.ToString(), bSuccess ? TEXT("SUCCESS (Scar Cleansed)") : TEXT("FAILED"));
}
