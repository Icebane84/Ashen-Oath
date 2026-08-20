// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenDeterministicVoiceFallbackProvider.h"

UAshenDeterministicVoiceFallbackProvider::UAshenDeterministicVoiceFallbackProvider()
{
}

FAshenInnerVoicePayload UAshenDeterministicVoiceFallbackProvider::GetFallbackPayload(
	EOntologicalLens DominantLens,
	float IntegrationDebt,
	const FString& CitedMemoryId) const
{
	FAshenInnerVoicePayload Payload;
	Payload.CompilationId = FGuid::NewGuid().ToString();
	Payload.CitedMemoryId = CitedMemoryId;
	Payload.ConfidenceScore = 1.0f;
	Payload.ValidationResult = EFirewallValidationResult::Success;

	if (DominantLens == EOntologicalLens::Defiance)
	{
		Payload.Channel = EVoiceChannel::KaelenReflex;
		Payload.MonologueText = TEXT("I must bear this alone. Let the blade take what it will, so long as they stand.");
		Payload.AudioMotifTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Audio.Motif.Whisper.Left.LowResonance")), false);
		Payload.DistortionIntensity = FMath::Clamp(IntegrationDebt * 0.50f, 0.0f, 1.0f);
	}
	else if (DominantLens == EOntologicalLens::Grace)
	{
		Payload.Channel = EVoiceChannel::Eldrin;
		Payload.MonologueText = TEXT("The ash does not seek to burn again. Let them hold the line with you.");
		Payload.AudioMotifTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Audio.Motif.Echo.Center.Harmonic")), false);
		Payload.DistortionIntensity = 0.15f;
	}
	else // Wrath
	{
		Payload.Channel = EVoiceChannel::ShadowSelf;
		Payload.MonologueText = TEXT("They will never understand what survival cost you. Tear through them.");
		Payload.AudioMotifTag = FGameplayTag::RequestGameplayTag(FName(TEXT("Audio.Motif.Whisper.Right.Dissonant")), false);
		Payload.DistortionIntensity = FMath::Clamp(0.50f + (IntegrationDebt * 0.40f), 0.0f, 1.0f);
	}

	return Payload;
}
