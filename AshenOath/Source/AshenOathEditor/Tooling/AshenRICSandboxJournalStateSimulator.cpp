// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenRICSandboxJournalStateSimulator.h"

void UAshenRICSandboxJournalStateSimulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	SimulateJournalStateDegradation(0.75f);
}

void UAshenRICSandboxJournalStateSimulator::Deinitialize()
{
	Super::Deinitialize();
}

bool UAshenRICSandboxJournalStateSimulator::SimulateJournalStateDegradation(float InCorruption)
{
	LastSimulatedCorruption = InCorruption;
	UE_LOG(LogTemp, Log, TEXT("UAshenRICSandboxJournalStateSimulator: Simulated journal degradation at Corruption %.2f"), LastSimulatedCorruption);
	return true;
}
