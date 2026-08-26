// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenDynamicRubblePhysicsSubsystem.h"

UAshenDynamicRubblePhysicsSubsystem::UAshenDynamicRubblePhysicsSubsystem()
{
	CurrentHazard.StructuralIntegrity01 = 1.0f;
	CurrentHazard.TelegraphRadiusUU = 350.0f;
	CurrentHazard.CrushingImpactDamage = 600.0f;
	CurrentHazard.CollapseState = EMasonryCollapseState::StableIntact;

	CurrentCluster.TotalMassKg = 250.0f;
	CurrentCluster.RubbleRadiusUU = 300.0f;
	CurrentCluster.NavmeshCostModifier = 2.5f;
	CurrentCluster.FractureTier = ERubbleFractureTier::MediumMasonry;
	CurrentCluster.bIsChokePointBlocked = false;
}

void UAshenDynamicRubblePhysicsSubsystem::ApplyStructuralStrain(float StrainDelta)
{
	CurrentHazard.StructuralIntegrity01 = FMath::Clamp(CurrentHazard.StructuralIntegrity01 - StrainDelta, 0.0f, 1.0f);

	if (CurrentHazard.StructuralIntegrity01 <= 0.0f)
	{
		CurrentHazard.CollapseState = EMasonryCollapseState::CollapsingImpact;
		CurrentCluster.bIsChokePointBlocked = true;
		CurrentCluster.NavmeshCostModifier = 4.5f;
		OnMasonryCollapseStateChanged.Broadcast(CurrentHazard.CollapseState, CurrentHazard.StructuralIntegrity01);
		OnFallingHazardTelegraphed.Broadcast(CurrentHazard);
		OnRubbleNavmeshUpdated.Broadcast(CurrentCluster.NavmeshCostModifier, false);
	}
	else if (CurrentHazard.StructuralIntegrity01 <= 0.30f)
	{
		CurrentHazard.CollapseState = EMasonryCollapseState::TelegraphWarning;
		OnMasonryCollapseStateChanged.Broadcast(CurrentHazard.CollapseState, CurrentHazard.StructuralIntegrity01);
		OnFallingHazardTelegraphed.Broadcast(CurrentHazard);
	}
	else if (CurrentHazard.StructuralIntegrity01 <= 0.70f)
	{
		CurrentHazard.CollapseState = EMasonryCollapseState::StressGroaning;
		OnMasonryCollapseStateChanged.Broadcast(CurrentHazard.CollapseState, CurrentHazard.StructuralIntegrity01);
	}
}

void UAshenDynamicRubblePhysicsSubsystem::DemolishRubble(EDemolitionToolType ToolType, float AppliedForce)
{
	if (ToolType == EDemolitionToolType::None)
	{
		return;
	}

	float ClearedMass = FMath::Min(CurrentCluster.TotalMassKg, AppliedForce * 0.5f);
	CurrentCluster.TotalMassKg = FMath::Clamp(CurrentCluster.TotalMassKg - ClearedMass, 0.0f, 1000.0f);

	if (CurrentCluster.TotalMassKg <= 25.0f)
	{
		CurrentCluster.FractureTier = ERubbleFractureTier::FineGravel;
		CurrentCluster.bIsChokePointBlocked = false;
		CurrentCluster.NavmeshCostModifier = 1.0f;
	}
	else if (CurrentCluster.TotalMassKg <= 150.0f)
	{
		CurrentCluster.FractureTier = ERubbleFractureTier::MediumMasonry;
		CurrentCluster.NavmeshCostModifier = 1.8f;
	}

	OnRubbleDemolished.Broadcast(ToolType, ClearedMass);
	OnRubbleNavmeshUpdated.Broadcast(CurrentCluster.NavmeshCostModifier, !CurrentCluster.bIsChokePointBlocked);
}
