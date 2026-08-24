// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenScenario8AudioSubsystem.h"

UAshenScenario8AudioSubsystem::UAshenScenario8AudioSubsystem()
{
}

float UAshenScenario8AudioSubsystem::EvaluateReverbDecayTime(float CavernVolumeM3) const
{
	// 500m3 to 10000m3 scales 1.5s to 6.0s RT60 reverb
	const float Alpha = FMath::Clamp((CavernVolumeM3 - 500.0f) / 9500.0f, 0.0f, 1.0f);
	return FMath::Lerp(1.5f, 6.0f, Alpha);
}
