// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCompanionFormationHapticAdapter.h"

UAshenCompanionFormationHapticAdapter::UAshenCompanionFormationHapticAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	LastStride = 1.0f;
}

void UAshenCompanionFormationHapticAdapter::TriggerFormationFootstepHaptic(float StrideCadence)
{
	LastStride = FMath::Clamp(StrideCadence, 0.5f, 2.0f);
}
