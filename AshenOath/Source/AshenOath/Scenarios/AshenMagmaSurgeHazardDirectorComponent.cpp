// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenMagmaSurgeHazardDirectorComponent.h"

UAshenMagmaSurgeHazardDirectorComponent::UAshenMagmaSurgeHazardDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ECalderaSurgePhase UAshenMagmaSurgeHazardDirectorComponent::EvaluateSurgePhaseFromTime(float ElapsedSeconds) const
{
	const float ModTime = FMath::Fmod(ElapsedSeconds, 15.0f);

	if (ModTime < 10.0f)
	{
		return ECalderaSurgePhase::DormantCalm;
	}
	else if (ModTime < 13.0f)
	{
		return ECalderaSurgePhase::TelegraphWarning;
	}

	return ECalderaSurgePhase::ActiveEruption;
}
