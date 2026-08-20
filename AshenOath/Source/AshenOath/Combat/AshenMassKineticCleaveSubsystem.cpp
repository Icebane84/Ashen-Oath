// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenMassKineticCleaveSubsystem.h"
#include "Combat/AshenMassKineticCleaveComponent.h"
#include "Combat/AshenWeaponResistanceWarperComponent.h"
#include "Combat/AshenCameraResistanceDilationComponent.h"

UAshenMassKineticCleaveSubsystem::UAshenMassKineticCleaveSubsystem()
{
}

void UAshenMassKineticCleaveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CleaveComponent = NewObject<UAshenMassKineticCleaveComponent>(this);
	WarperComponent = NewObject<UAshenWeaponResistanceWarperComponent>(this);
	DilationComponent = NewObject<UAshenCameraResistanceDilationComponent>(this);
}

void UAshenMassKineticCleaveSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

FKineticSwingSnapshot UAshenMassKineticCleaveSubsystem::EvaluateSwingKinetics(
	EKineticCleaveStance Stance,
	float BladeTipVelocityMetersPerSec)
{
	FKineticSwingSnapshot Snapshot;

	if (CleaveComponent)
	{
		Snapshot = CleaveComponent->CalculateKineticPayload(Stance, BladeTipVelocityMetersPerSec);
		OnKineticSwingCalculated.Broadcast(Snapshot);
	}

	return Snapshot;
}

FVolumeDragResult UAshenMassKineticCleaveSubsystem::ProcessMatterVolumeDrag(float SubmergedVolumeCM3)
{
	FVolumeDragResult DragResult;

	if (WarperComponent && DilationComponent)
	{
		DragResult.SubmergedVolumeCM3 = SubmergedVolumeCM3;
		DragResult.AdjustedAnimPlayRate = WarperComponent->CalculatePlayRateForVolume(SubmergedVolumeCM3);
		DragResult.CompressedFOV = DilationComponent->CalculateCompressedFOV(SubmergedVolumeCM3);
		DragResult.bShearedThroughMatter = (SubmergedVolumeCM3 <= 0.0f);

		OnVolumeDragUpdated.Broadcast(DragResult);
	}

	return DragResult;
}

void UAshenMassKineticCleaveSubsystem::RecordStructuralDestruction(const FVector& ImpactLocation, float EnergyJoules)
{
	OnStructuralDestructionTriggered.Broadcast(ImpactLocation, EnergyJoules);
}
