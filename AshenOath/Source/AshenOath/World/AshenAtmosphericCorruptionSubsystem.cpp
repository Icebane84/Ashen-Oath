// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 355: Ashen Atmospheric Corruption Subsystem

#include "AshenAtmosphericCorruptionSubsystem.h"

void UAshenAtmosphericCorruptionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentHazard = EAshenAtmosphericHazard::None;
	UE_LOG(LogTemp, Log, TEXT("UAshenAtmosphericCorruptionSubsystem: Initialized — Atmospheric Corruption Subsystem ONLINE."));
}

void UAshenAtmosphericCorruptionSubsystem::SetActiveAtmosphericHazard(EAshenAtmosphericHazard NewHazard, float SeverityRate)
{
	CurrentHazard = NewHazard;
	OnAtmosphericHazardTriggered.Broadcast(NewHazard, SeverityRate);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAtmosphericCorruptionSubsystem: ATMOSPHERIC HAZARD ENGAGED -> Type %d (Severity Rate: %.1f/s)."),
		(int32)NewHazard, SeverityRate);
}
