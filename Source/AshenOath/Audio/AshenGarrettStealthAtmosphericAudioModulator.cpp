// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 714: Ashen Garrett Stealth Atmospheric Audio Modulator

#include "AshenGarrettStealthAtmosphericAudioModulator.h"

void UAshenGarrettStealthAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettStealthAtmosphericAudioModulator: Initialized — Garrett Stealth Atmospheric Audio Modulator ONLINE."));
}

void UAshenGarrettStealthAtmosphericAudioModulator::ModulateGarrettStealthAudio(bool bIsStealthed, float ThreatLevel)
{
	TotalAudioModulationsApplied++;
	const float TensionVol = bIsStealthed ? 0.3f : 0.8f;
	const float Damping = bIsStealthed ? 0.9f : 0.0f; // 90% footstep sound damping during stealth

	OnGarrettAudioModulated.Broadcast(TensionVol, Damping);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettStealthAtmosphericAudioModulator: STEALTH AUDIO MODULATED -> Tension Vol: %.2f | Footstep Damping: %.2f (Total: %d)."),
		TensionVol, Damping, TotalAudioModulationsApplied);
}
