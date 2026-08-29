// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenCSEAudioSubsystem.h"

UAshenCSEAudioSubsystem::UAshenCSEAudioSubsystem()
{
}

void UAshenCSEAudioSubsystem::EvaluateCSEAcoustics(
	float DissonanceIndex,
	float& OutHarmonyChimeGain,
	float& OutDissonantScrapeGain,
	float& OutDetuneHz) const
{
	const float SafeD = FMath::Clamp(DissonanceIndex, 0.0f, 1.0f);

	// 432Hz Harmony Chime Gain
	OutHarmonyChimeGain = FMath::Clamp(1.0f - (SafeD * 1.5f), 0.0f, 1.0f);

	// 110Hz Dissonant Scrape Gain
	OutDissonantScrapeGain = SafeD;

	// Detune offset (0Hz to 25Hz dissonant beating)
	OutDetuneHz = SafeD * 25.0f;
}
