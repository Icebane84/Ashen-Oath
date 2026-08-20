// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 774: Ashen Blackwood Bridge Atmospheric Audio Modulator

#include "AshenBlackwoodBridgeAtmosphericAudioModulator.h"

void UAshenBlackwoodBridgeAtmosphericAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioModulationsApplied = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenBlackwoodBridgeAtmosphericAudioModulator: Initialized — Blackwood Bridge Atmospheric Audio Modulator ONLINE."));
}

void UAshenBlackwoodBridgeAtmosphericAudioModulator::ModulateBlackwoodAudio(bool bInBossCombat, float StormIntensity)
{
	TotalAudioModulationsApplied++;
	const float MusicVol = bInBossCombat ? 1.0f : 0.3f;
	const float StormVol = FMath::Clamp(StormIntensity / 100.0f, 0.1f, 1.0f);

	OnBlackwoodAudioModulated.Broadcast(MusicVol, StormVol);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBlackwoodBridgeAtmosphericAudioModulator: AUDIO MODULATED -> Music Vol: %.2f | Storm Vol: %.2f (Total: %d)."),
		MusicVol, StormVol, TotalAudioModulationsApplied);
}
