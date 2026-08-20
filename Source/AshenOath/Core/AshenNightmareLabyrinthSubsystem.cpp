// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 331: Ashen Nightmare Labyrinth Subsystem

#include "AshenNightmareLabyrinthSubsystem.h"

void UAshenNightmareLabyrinthSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveTrialID = NAME_None;
	UE_LOG(LogTemp, Log, TEXT("UAshenNightmareLabyrinthSubsystem: Initialized — Nightmare Labyrinth Trials active."));
}

bool UAshenNightmareLabyrinthSubsystem::StartNightmareTrial(FName TrialID)
{
	if (TrialID.IsNone()) return false;

	ActiveTrialID = TrialID;

	UE_LOG(LogTemp, Warning, TEXT("UAshenNightmareLabyrinthSubsystem: NIGHTMARE TRIAL INITIATED — '%s'."), *TrialID.ToString());

	return true;
}

void UAshenNightmareLabyrinthSubsystem::CompleteNightmareTrial(FName TrialID, bool bSuccess)
{
	OnNightmareTrialCompleted.Broadcast(TrialID, bSuccess);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNightmareLabyrinthSubsystem: NIGHTMARE TRIAL '%s' FINISHED — Result: %s."),
		*TrialID.ToString(), bSuccess ? TEXT("PASSED (Skill Evolved)") : TEXT("FAILED"));
}
