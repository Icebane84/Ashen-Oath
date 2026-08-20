// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 498: Ashen Diegetic Audio Distortion Subsystem

#include "AshenDiegeticAudioDistortionSubsystem.h"

void UAshenDiegeticAudioDistortionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAudioDistortionSubsystem: Initialized — Diegetic Audio Distortion Subsystem ONLINE."));
}

void UAshenDiegeticAudioDistortionSubsystem::ModulateAudioDistortionForSanity(float SanityPercent)
{
	const float Normalized = FMath::Clamp(SanityPercent / 100.0f, 0.0f, 1.0f);
	const float PitchMultiplier = FMath::Lerp(0.6f, 1.0f, Normalized);
	const float TinnitusVolume = (1.0f - Normalized) * 0.8f;

	OnAudioDistortionModulated.Broadcast(PitchMultiplier, TinnitusVolume);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticAudioDistortionSubsystem: AUDIO DISTORTION MODULATED -> Sanity %.1f%% (Pitch Multiplier: %.2f | Tinnitus Volume: %.2f)."),
		SanityPercent, PitchMultiplier, TinnitusVolume);
}
