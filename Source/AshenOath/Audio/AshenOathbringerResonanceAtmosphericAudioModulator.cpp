// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 794: Ashen Oathbringer Resonance Atmospheric Audio Modulator

#include "AshenOathbringerResonanceAtmosphericAudioModulator.h"

void UAshenOathbringerResonanceAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerResonanceAtmosphericAudioModulator: Initialized — Oathbringer Resonance Atmospheric Audio Modulator ONLINE."));
}

void UAshenOathbringerResonanceAtmosphericAudioModulator::ModulateResonanceAudio(float BladeResonancePercent)
{
	TotalAudioModulationsApplied++;
	const float PitchMult = 1.0f + (BladeResonancePercent * 0.005f); // Pitch swells up to 1.5x at max resonance
	const float HarmonicVol = FMath::Clamp(BladeResonancePercent / 100.0f, 0.0f, 1.0f);

	OnResonanceAudioModulated.Broadcast(PitchMult, HarmonicVol);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerResonanceAtmosphericAudioModulator: RESONANCE AUDIO MODULATED -> Pitch Mult: %.2fx | Harmonic Vol: %.2f (Total: %d)."),
		PitchMult, HarmonicVol, TotalAudioModulationsApplied);
}
