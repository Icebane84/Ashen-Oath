// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 673: Ashen Harmonic Purification Synergy Subsystem

#include "AshenHarmonicPurificationSynergySubsystem.h"

void UAshenHarmonicPurificationSynergySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalPurificationsExecuted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenHarmonicPurificationSynergySubsystem: Initialized — Harmonic Purification Synergy Subsystem ONLINE."));
}

void UAshenHarmonicPurificationSynergySubsystem::ExecuteHarmonicPurificationFromParry(float BaseRestoration)
{
	TotalPurificationsExecuted++;
	const float EmpathicResonance = BaseRestoration * 1.25f;
	OnHarmonicPurificationExecuted.Broadcast(BaseRestoration, EmpathicResonance);

	UE_LOG(LogTemp, Warning, TEXT("UAshenHarmonicPurificationSynergySubsystem: HARMONIC PURIFICATION EXECUTED -> Restored Stamina: %.1f | Resonance: %.1f (Total: %d)."),
		BaseRestoration, EmpathicResonance, TotalPurificationsExecuted);
}
