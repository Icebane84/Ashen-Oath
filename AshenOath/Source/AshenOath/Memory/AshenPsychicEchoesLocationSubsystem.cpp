// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 373: Ashen Psychic Echoes Location Subsystem

#include "AshenPsychicEchoesLocationSubsystem.h"

void UAshenPsychicEchoesLocationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LocationEchoes.Empty();
	UE_LOG(LogTemp, Log, TEXT("UAshenPsychicEchoesLocationSubsystem: Initialized — Psychic Echoes World Map ONLINE."));
}

void UAshenPsychicEchoesLocationSubsystem::ImprintPsychicEchoAtLocation(FName LocationID, float Intensity)
{
	if (LocationID.IsNone()) return;

	LocationEchoes.Add(LocationID, Intensity);
	OnPsychicEchoCreated.Broadcast(LocationID, Intensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPsychicEchoesLocationSubsystem: PSYCHIC ECHO IMPRINTED AT '%s' (Intensity: %.1f)."),
		*LocationID.ToString(), Intensity);
}

float UAshenPsychicEchoesLocationSubsystem::GetLocationEchoIntensity(FName LocationID) const
{
	return LocationEchoes.Contains(LocationID) ? LocationEchoes[LocationID] : 0.0f;
}
