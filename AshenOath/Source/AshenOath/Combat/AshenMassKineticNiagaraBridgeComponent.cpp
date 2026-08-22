// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMassKineticNiagaraBridgeComponent.h"

UAshenMassKineticNiagaraBridgeComponent::UAshenMassKineticNiagaraBridgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FAshenNiagaraShearTraceData UAshenMassKineticNiagaraBridgeComponent::ComputeExitShearVector(
	const FVector& EntryPoint,
	const FVector& SwingTrajectory,
	float ObjectDepthCentimeters,
	float KineticJoules) const
{
	FAshenNiagaraShearTraceData Result;
	Result.BladeEntryCoordinate = EntryPoint;
	Result.ExitShearTrajectory = SwingTrajectory.GetSafeNormal();
	Result.BladeExitCoordinate = EntryPoint + (Result.ExitShearTrajectory * ObjectDepthCentimeters);
	Result.KineticEnergyJoules = KineticJoules;
	return Result;
}
