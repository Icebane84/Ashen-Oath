// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 754: Ashen Whispering Void Atmospheric Audio Modulator

#include "AshenWhisperingVoidAtmosphericAudioModulator.h"

void UAshenWhisperingVoidAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingVoidAtmosphericAudioModulator: Initialized — Whispering Void Atmospheric Audio Modulator ONLINE."));
}

void UAshenWhisperingVoidAtmosphericAudioModulator::ModulateVoidAudio(float VoidErosionIntensity)
{
	TotalAudioModulationsApplied++;
	const float DissonantVol = FMath::Clamp(VoidErosionIntensity / 100.0f, 0.0f, 1.0f);
	const float CutoffFreq = 20000.0f - (DissonantVol * 15000.0f); // Low pass filter muffling ambient sound

	OnVoidAudioModulated.Broadcast(DissonantVol, CutoffFreq);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWhisperingVoidAtmosphericAudioModulator: VOID AUDIO MODULATED -> Dissonant Vol: %.2f | Cutoff Freq: %.0f Hz (Total: %d)."),
		DissonantVol, CutoffFreq, TotalAudioModulationsApplied);
}
