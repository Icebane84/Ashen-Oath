// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 717: Ashen Serafina Radiant Purge Nova Subsystem

#include "AshenSerafinaRadiantPurgeNovaSubsystem.h"

void UAshenSerafinaRadiantPurgeNovaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalPurgesExecuted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaRadiantPurgeNovaSubsystem: Initialized — Serafina Radiant Purge Nova Subsystem ONLINE."));
}

void UAshenSerafinaRadiantPurgeNovaSubsystem::ExecuteRadiantPurgeNova(float CurrentSpiritualStain)
{
	TotalPurgesExecuted++;
	const float CleansedAmount = 25.0f; // Cleanses 25% stain
	const float NewStain = FMath::Clamp(CurrentSpiritualStain - CleansedAmount, 0.0f, 100.0f);

	OnRadiantPurgeExecuted.Broadcast(CleansedAmount, NewStain);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaRadiantPurgeNovaSubsystem: RADIANT PURGE NOVA EXECUTED -> Cleansed: -%.1f%% | New Stain: %.1f%% (Total Purges: %d)."),
		CleansedAmount, NewStain, TotalPurgesExecuted);
}
