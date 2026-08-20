// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 834: Ashen Crisis State Atmospheric Audio Modulator

#include "AshenCrisisStateAtmosphericAudioModulator.h"

void UAshenCrisisStateAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioTransitionsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenCrisisStateAtmosphericAudioModulator: Initialized — Crisis State Atmospheric Audio Modulator ONLINE."));
}

void UAshenCrisisStateAtmosphericAudioModulator::ModulateCrisisAudioState(FName ResolutionTag)
{
	TotalAudioTransitionsApplied++;
	float VacuumDb = -48.0f;
	float BellVol = 0.0f;

	if (ResolutionTag.IsEqual(FName(TEXT("Resolution.ResistWhiteFlameUnbroken"))))
	{
		VacuumDb = 0.0f;  // Normal ambient audio returns
		BellVol = 1.0f;   // Pure resonant bell tone sounds
	}
	else
	{
		VacuumDb = -60.0f; // Deep vacuum sound tear
		BellVol = 0.0f;
	}

	OnCrisisAudioModulated.Broadcast(VacuumDb, BellVol);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCrisisStateAtmosphericAudioModulator: CRISIS AUDIO MODULATED -> Resolution: '%s' | Ambient Vacuum: %.1f dB | Resonant Bell: %.2f (Total: %d)."),
		*ResolutionTag.ToString(), VacuumDb, BellVol, TotalAudioTransitionsApplied);
}
