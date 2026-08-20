// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 508: Ashen Failure Memory Psychic Echo Subsystem

#include "AshenFailureMemoryPsychicEchoSubsystem.h"

void UAshenFailureMemoryPsychicEchoSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ImprintedFailures.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenFailureMemoryPsychicEchoSubsystem: Initialized — Failure Memory Psychic Echo Engine ONLINE."));
}

void UAshenFailureMemoryPsychicEchoSubsystem::ImprintFailurePsychicEcho(FName FailureID, FVector EchoLocation)
{
	if (FailureID.IsNone()) return;

	ImprintedFailures.AddUnique(FailureID);
	OnPsychicEchoImprinted.Broadcast(FailureID, EchoLocation);

	UE_LOG(LogTemp, Error, TEXT("UAshenFailureMemoryPsychicEchoSubsystem: FAILURE PSYCHIC ECHO IMPRINTED -> '%s' at (%s) — Virtue Fracture Inflicted!"),
		*FailureID.ToString(), *EchoLocation.ToString());
}
