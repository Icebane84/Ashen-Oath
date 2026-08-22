// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenKineticBerserkSubsystem.h"

UAshenKineticBerserkSubsystem::UAshenKineticBerserkSubsystem()
{
	TotalRipostesExecuted = 0;
}

void UAshenKineticBerserkSubsystem::NotifyAngularCounterMapped(EAshenCounterAttackZone Zone, float AngleDegrees)
{
	TotalRipostesExecuted++;
	OnAngularCounterMapped.Broadcast(Zone, AngleDegrees);
}

void UAshenKineticBerserkSubsystem::NotifyDebrisOcclusionUpdated(float CutoffFrequency, EAshenDebrisOcclusionState State)
{
	OnDebrisOcclusionUpdated.Broadcast(CutoffFrequency, State);
}

void UAshenKineticBerserkSubsystem::NotifyPlanarExitShear(const FVector& ExitCoordinate, const FVector& ShearVector)
{
	OnPlanarExitShearSpawned.Broadcast(ExitCoordinate, ShearVector);
}
