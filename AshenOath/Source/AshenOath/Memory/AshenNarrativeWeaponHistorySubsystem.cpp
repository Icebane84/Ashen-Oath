// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenNarrativeWeaponHistorySubsystem.h"

void UAshenNarrativeWeaponHistorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalOathbringerKills = 0;
	TotalWeaponExecutions = 0;
	InscribedRuneTiers = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenNarrativeWeaponHistorySubsystem: Narrative Weapon History Subsystem initialized."));
}

void UAshenNarrativeWeaponHistorySubsystem::RecordWeaponKillImprint(FName WeaponID)
{
	TotalOathbringerKills++;
	if (OnWeaponHistoryRecorded.IsBound())
	{
		OnWeaponHistoryRecorded.Broadcast(WeaponID, TotalOathbringerKills);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenNarrativeWeaponHistorySubsystem: Recorded kill imprint for %s (Total: %d)"),
		*WeaponID.ToString(), TotalOathbringerKills);
}

void UAshenNarrativeWeaponHistorySubsystem::RecordExecutionKill(FName VictimType)
{
	TotalWeaponExecutions++;
	TotalOathbringerKills++;
	if (TotalWeaponExecutions % 10 == 0)
	{
		InscribedRuneTiers++;
		const FName RuneID(*FString::Printf(TEXT("Rune_Tier_%d"), InscribedRuneTiers));
		if (OnWeaponRuneInscribed.IsBound())
		{
			OnWeaponRuneInscribed.Broadcast(RuneID, InscribedRuneTiers);
		}
		UE_LOG(LogTemp, Warning, TEXT("UAshenNarrativeWeaponHistorySubsystem: NEW RUNE TIER INSCRIBED (%s) after %d executions!"),
			*RuneID.ToString(), TotalWeaponExecutions);
	}
}
