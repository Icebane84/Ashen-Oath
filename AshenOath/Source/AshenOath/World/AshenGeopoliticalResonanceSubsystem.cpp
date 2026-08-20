// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 548: Ashen Geopolitical Resonance Subsystem

#include "AshenGeopoliticalResonanceSubsystem.h"

void UAshenGeopoliticalResonanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenGeopoliticalResonanceSubsystem: Initialized — Geopolitical Resonance Subsystem ONLINE."));
}

void UAshenGeopoliticalResonanceSubsystem::ModifyFactionReputation(FName FactionID, float Delta)
{
	if (FactionID.IsNone()) return;

	const float Score = 50.0f + Delta;
	OnReputationShifted.Broadcast(FactionID, Score);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGeopoliticalResonanceSubsystem: FACTION REPUTATION SHIFTED -> '%s' (Delta: %+.1f | Score: %.1f)."),
		*FactionID.ToString(), Delta, Score);
}
