// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_RubbleHazardHUD.h"

UAshenUserWidget_RubbleHazardHUD::UAshenUserWidget_RubbleHazardHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedHazard.StructuralIntegrity01 = 1.0f;
	DisplayedHazard.TelegraphRadiusUU = 350.0f;
	DisplayedHazard.CrushingImpactDamage = 600.0f;
	DisplayedHazard.CollapseState = EMasonryCollapseState::StableIntact;

	DisplayedCluster.TotalMassKg = 250.0f;
	DisplayedCluster.RubbleRadiusUU = 300.0f;
	DisplayedCluster.NavmeshCostModifier = 2.5f;
	DisplayedCluster.FractureTier = ERubbleFractureTier::MediumMasonry;
	DisplayedCluster.bIsChokePointBlocked = false;
}

void UAshenUserWidget_RubbleHazardHUD::UpdateHazardHUD(
	const FMasonryHazardVector& Hazard,
	const FRubblePhysicsClusterVector& Cluster)
{
	DisplayedHazard = Hazard;
	DisplayedCluster = Cluster;
}
