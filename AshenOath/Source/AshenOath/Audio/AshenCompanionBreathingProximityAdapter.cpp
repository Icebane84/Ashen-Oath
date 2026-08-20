// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenCompanionBreathingProximityAdapter.h"
#include "Components/AudioComponent.h"

UAshenCompanionBreathingProximityAdapter::UAshenCompanionBreathingProximityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentVolume = 0.0f;
}

void UAshenCompanionBreathingProximityAdapter::UpdateBreathingProximity(
	float DistanceToKaelen,
	bool bIsSprinting)
{
	if (!bIsSprinting || DistanceToKaelen > 500.0f)
	{
		CurrentVolume = 0.0f;
		return;
	}

	CurrentVolume = FMath::Clamp(1.0f - (DistanceToKaelen / 500.0f), 0.0f, 1.0f);
	if (BreathingAudioComponent)
	{
		BreathingAudioComponent->SetVolumeMultiplier(CurrentVolume);
	}
}
