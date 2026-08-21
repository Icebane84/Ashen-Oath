// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenOakhavenAudioSubsystem.h"

UAshenOakhavenAudioSubsystem::UAshenOakhavenAudioSubsystem()
{
}

float UAshenOakhavenAudioSubsystem::EvaluateNullZoneCutoffHz(bool bNullZoneActive) const
{
	return bNullZoneActive ? 320.0f : 20000.0f; // Harsh muffled isolation during null zone
}

float UAshenOakhavenAudioSubsystem::EvaluateShadowWhisperVolume(float IntegrationDebt) const
{
	if (IntegrationDebt < 0.50f)
	{
		return 0.0f;
	}

	// Above 50% debt, whisper volume ramps aggressively
	return FMath::Clamp((IntegrationDebt - 0.50f) / 0.50f, 0.0f, 1.0f);
}
