// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 213: Ashen Sanity Corrupted Audio Component

#include "AshenSanityCorruptedAudioComponent.h"

UAshenSanityCorruptedAudioComponent::UAshenSanityCorruptedAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MinPitch = 0.65f;
	MaxPitch = 1.0f;
	CurrentPitchMultiplier = 1.0f;
}

void UAshenSanityCorruptedAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSanityCorruptedAudioComponent::UpdateAudioCorruption(float CurrentSanity, float MaxSanity)
{
	if (MaxSanity <= 0.0f) return;

	const float SanityRatio = FMath::Clamp(CurrentSanity / MaxSanity, 0.0f, 1.0f);
	CurrentPitchMultiplier = FMath::Lerp(MinPitch, MaxPitch, SanityRatio);

	OnAudioCorrupted.Broadcast(SanityRatio, CurrentPitchMultiplier);

	UE_LOG(LogTemp, Log, TEXT("UAshenSanityCorruptedAudioComponent: Sanity ratio %.1f%% — Audio Pitch Multiplier: %.2fx."),
		SanityRatio * 100.0f, CurrentPitchMultiplier);
}
