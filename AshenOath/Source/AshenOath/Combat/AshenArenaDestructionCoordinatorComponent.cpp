// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenArenaDestructionCoordinatorComponent.h"

UAshenArenaDestructionCoordinatorComponent::UAshenArenaDestructionCoordinatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalPillars = 4;
	IntactPillars = 4;
	ObstructionScalar = 0.0f;
}

float UAshenArenaDestructionCoordinatorComponent::SunderPillar(int32 PillarIndex)
{
	if (IntactPillars > 0)
	{
		IntactPillars--;
		const int32 SunderedPillars = TotalPillars - IntactPillars;
		ObstructionScalar = FMath::Clamp((float)SunderedPillars / (float)TotalPillars, 0.0f, 1.0f);
	}

	return ObstructionScalar;
}
