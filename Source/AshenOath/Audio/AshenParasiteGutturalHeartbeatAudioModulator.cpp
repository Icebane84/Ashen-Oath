// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 823: Ashen Parasite Guttural Heartbeat Audio Modulator

#include "AshenParasiteGutturalHeartbeatAudioModulator.h"

void UAshenParasiteGutturalHeartbeatAudioModulator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalAudioPulsesPlayed = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenParasiteGutturalHeartbeatAudioModulator: Initialized — Parasite Guttural Heartbeat Audio Modulator ONLINE."));
}

void UAshenParasiteGutturalHeartbeatAudioModulator::UpdateHeartbeatAudioPressure(float PromptTimerRemainingRatio)
{
	TotalAudioPulsesPlayed++;
	const float Pitch = 1.0f + ((1.0f - PromptTimerRemainingRatio) * 0.8f); // Pitch rises up to 1.8x as timer ticks down
	const float ScreamVol = 0.5f + ((1.0f - PromptTimerRemainingRatio) * 0.5f);

	OnHeartbeatAudioUpdated.Broadcast(Pitch, ScreamVol);

	UE_LOG(LogTemp, Warning, TEXT("UAshenParasiteGutturalHeartbeatAudioModulator: GUTTURAL HEARTBEAT AUDIO UPDATED -> Remaining Ratio: %.2f | Heartbeat Pitch: %.2fx | Companion Scream Vol: %.2f."),
		PromptTimerRemainingRatio, Pitch, ScreamVol);
}
