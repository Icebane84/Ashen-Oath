// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenDualSenseMetaSoundsSubsystem.h"

UAshenDualSenseMetaSoundsSubsystem::UAshenDualSenseMetaSoundsSubsystem()
{
}

float UAshenDualSenseMetaSoundsSubsystem::EvaluateSpeakerGain(float MasterVolume, bool bSpeakerMuted) const
{
	if (bSpeakerMuted)
	{
		return 0.0f;
	}

	return FMath::Clamp(MasterVolume, 0.0f, 1.0f);
}
