// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 378: Ashen Sanctuary Restoration Subsystem

#include "AshenSanctuaryRestorationSubsystem.h"

void UAshenSanctuaryRestorationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveSanctuaries.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryRestorationSubsystem: Initialized — Sanctuary Restoration Subsystem active."));
}

bool UAshenSanctuaryRestorationSubsystem::RekindleDormantHeartstone(FName SanctuaryID)
{
	if (SanctuaryID.IsNone()) return false;

	ActiveSanctuaries.Add(SanctuaryID);
	OnSanctuaryRekindled.Broadcast(SanctuaryID, ActiveSanctuaries.Num());

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryRestorationSubsystem: DORMANT HEARTSTONE REKINDLED — '%s' (Total Active Sanctuaries: %d)."),
		*SanctuaryID.ToString(), ActiveSanctuaries.Num());

	return true;
}
