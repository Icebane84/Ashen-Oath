// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 293: Ashen Audio Insanity Voice Subsystem

#include "AshenAudioInsanityVoiceSubsystem.h"

void UAshenAudioInsanityVoiceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenAudioInsanityVoiceSubsystem: Initialized — Auditory Whisper Subsystem active."));
}

void UAshenAudioInsanityVoiceSubsystem::TriggerInsanityVoiceBark(float SanityPercentage)
{
	const float PitchMult = FMath::Lerp(0.70f, 1.0f, FMath::Clamp(SanityPercentage / 100.0f, 0.0f, 1.0f));
	const FName BarkID(TEXT("Whisper_Mindscape_Paranoia"));

	OnInsanityVoiceBark.Broadcast(BarkID, PitchMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAudioInsanityVoiceSubsystem: INSANITY VOICE BARK '%s' played — Pitch: %.2fx (Sanity: %.1f%%)."),
		*BarkID.ToString(), PitchMult, SanityPercentage);
}
