// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 170: Ashen Combat Replay Component

#include "AshenCombatReplayComponent.h"
#include "Engine/World.h"

UAshenCombatReplayComponent::UAshenCombatReplayComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxLogEntries = 10;
}

void UAshenCombatReplayComponent::BeginPlay()
{
	Super::BeginPlay();
	SessionStartTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
}

void UAshenCombatReplayComponent::RecordCombatEvent(const FString& Description, float DamageDealt)
{
	// Rolling buffer — remove oldest entry when at capacity
	if (CombatLog.Num() >= MaxLogEntries)
	{
		CombatLog.RemoveAt(0);
	}

	FAshenCombatEvent Event;
	Event.EventDescription = Description;
	Event.DamageDealt = DamageDealt;
	Event.Timestamp = GetWorld() ? (GetWorld()->GetTimeSeconds() - SessionStartTime) : 0.0f;

	CombatLog.Add(Event);

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatReplayComponent: Logged combat event [T+%.1fs] '%s' (%.0f dmg)."),
		Event.Timestamp, *Description, DamageDealt);
}

void UAshenCombatReplayComponent::TriggerDeathRecap()
{
	OnDeathReplayReady.Broadcast(CombatLog);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatReplayComponent: DEATH RECAP triggered — broadcasting %d combat events."),
		CombatLog.Num());

	for (int32 i = 0; i < CombatLog.Num(); ++i)
	{
		UE_LOG(LogTemp, Warning, TEXT("  [%d] T+%.1fs | %s | %.0f dmg"),
			i, CombatLog[i].Timestamp, *CombatLog[i].EventDescription, CombatLog[i].DamageDealt);
	}
}

void UAshenCombatReplayComponent::ClearLog()
{
	CombatLog.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenCombatReplayComponent: Combat log cleared."));
}
