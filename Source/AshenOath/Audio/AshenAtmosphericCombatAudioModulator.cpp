// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 694: Ashen Atmospheric Combat Audio Modulator

#include "AshenAtmosphericCombatAudioModulator.h"

void UAshenAtmosphericCombatAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenAtmosphericCombatAudioModulator: Initialized — Atmospheric Combat Audio Modulator ONLINE."));
}

void UAshenAtmosphericCombatAudioModulator::ModulateAtmosphericCombatAudio(bool bIsUnchainedBerserk, float NarrativeEntropyLevel)
{
	TotalAudioModulationsApplied++;
	const float PitchFilter = bIsUnchainedBerserk ? 0.7f : 1.0f; // Lowers pitch during berserk
	const float WhisperVol = FMath::Clamp(NarrativeEntropyLevel / 100.0f, 0.0f, 1.0f);

	OnAtmosphericAudioModulated.Broadcast(PitchFilter, WhisperVol);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAtmosphericCombatAudioModulator: ATMOSPHERIC AUDIO MODULATED -> Pitch Filter: %.2f | Whisper Volume: %.2f (Total: %d)."),
		PitchFilter, WhisperVol, TotalAudioModulationsApplied);
}
