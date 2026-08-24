// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenChaosNavmeshSubsystem.h"

UAshenChaosNavmeshSubsystem::UAshenChaosNavmeshSubsystem()
{
	LatestCluster.FractureSeverity = EChaosFractureSeverity::IntactSolid;
	LatestCluster.ObstructionState = ENavmeshObstructionState::ClearPath;
	LatestCluster.MaterialType = EStructuralMaterialType::GraniteStone;
	LatestCluster.ClusterLocation = FVector::ZeroVector;
	LatestCluster.TotalDebrisMassKg = 0.0f;
	LatestCluster.NavmeshBlockingRadiusUU = 250.0f;
	LatestCluster.AcousticImpulseJoules = 0.0f;
	LatestCluster.bRequiresDetour = false;
}

void UAshenChaosNavmeshSubsystem::RegisterFractureEvent(
	EChaosFractureSeverity Severity,
	EStructuralMaterialType Material,
	const FVector& Location,
	float ImpactJoules,
	float DebrisMassKg)
{
	LatestCluster.FractureSeverity = Severity;
	LatestCluster.MaterialType = Material;
	LatestCluster.ClusterLocation = Location;
	LatestCluster.AcousticImpulseJoules = ImpactJoules;
	LatestCluster.TotalDebrisMassKg = DebrisMassKg;

	// Compute blocking radius: 150uu base + scaling with mass
	LatestCluster.NavmeshBlockingRadiusUU = FMath::Clamp(150.0f + (DebrisMassKg * 2.5f), 150.0f, 800.0f);

	if (Severity == EChaosFractureSeverity::TotalDemolition || DebrisMassKg >= 150.0f)
	{
		LatestCluster.ObstructionState = ENavmeshObstructionState::BlockedHighRubble;
		LatestCluster.bRequiresDetour = true;
	}
	else if (Severity == EChaosFractureSeverity::PartialCollapse || DebrisMassKg >= 40.0f)
	{
		LatestCluster.ObstructionState = ENavmeshObstructionState::VaultableLowDebris;
		LatestCluster.bRequiresDetour = false;
	}
	else
	{
		LatestCluster.ObstructionState = ENavmeshObstructionState::ClearPath;
		LatestCluster.bRequiresDetour = false;
	}

	// Acoustic frequency calculation: Higher mass/energy -> lower bass groan
	const float BaseFreq = (Material == EStructuralMaterialType::TimberSupport) ? 1200.0f : 450.0f;
	const float CalculatedFreq = FMath::Clamp(BaseFreq - (ImpactJoules / 50.0f), 120.0f, 4500.0f);

	OnChaosPillarFractured.Broadcast(Severity, Location, ImpactJoules);
	OnNavmeshObstructionChanged.Broadcast(Location, LatestCluster.ObstructionState);
	OnChaosSpatialAudioImpulse.Broadcast(Location, CalculatedFreq);
}

void UAshenChaosNavmeshSubsystem::ClearDebrisCluster(const FVector& Location)
{
	LatestCluster.ObstructionState = ENavmeshObstructionState::PulverizedCleared;
	LatestCluster.bRequiresDetour = false;
	LatestCluster.TotalDebrisMassKg = 0.0f;

	OnNavmeshObstructionChanged.Broadcast(Location, ENavmeshObstructionState::PulverizedCleared);
	OnDebrisClusterCleared.Broadcast(Location);
}
