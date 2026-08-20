// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 581: Ashen Abomination Boss Phase Subsystem

#include "AshenAbominationBossPhaseSubsystem.h"

void UAshenAbominationBossPhaseSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActivePhaseTier = 1;
	UE_LOG(LogTemp, Log, TEXT("UAshenAbominationBossPhaseSubsystem: Initialized — Abomination Void Phase Subsystem ONLINE."));
}

void UAshenAbominationBossPhaseSubsystem::TriggerAbominationVoidPhase(int32 PhaseTier, float Intensity)
{
	ActivePhaseTier = PhaseTier;
	OnVoidPhaseTriggered.Broadcast(ActivePhaseTier, Intensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAbominationBossPhaseSubsystem: ABOMINATION VOID PHASE TRIGGERED -> Tier %d | Smother Intensity: %.1f."),
		ActivePhaseTier, Intensity);
}
