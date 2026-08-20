// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 322: Ashen Corrupted Cadence Backlash Subsystem

#include "AshenCorruptedCadenceBacklashSubsystem.h"

void UAshenCorruptedCadenceBacklashSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	AccumulatedCadenceStrain = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCorruptedCadenceBacklashSubsystem: Initialized — Corrupted Cadence Tracker active."));
}

void UAshenCorruptedCadenceBacklashSubsystem::RecordDarkAbilityCast(float CorruptedCadenceCost)
{
	AccumulatedCadenceStrain += CorruptedCadenceCost;

	if (AccumulatedCadenceStrain >= 100.0f)
	{
		AccumulatedCadenceStrain = 0.0f;
		const FName Tag(TEXT("Backlash_InputLag_StaminaDrain"));

		OnPsychicBacklashTriggered.Broadcast(1.0f, Tag);

		UE_LOG(LogTemp, Warning, TEXT("UAshenCorruptedCadenceBacklashSubsystem: PSYCHIC BACKLASH ECHO TRIGGERED — Strain Limit Surpassed! Tag: '%s'."),
			*Tag.ToString());
	}
}
