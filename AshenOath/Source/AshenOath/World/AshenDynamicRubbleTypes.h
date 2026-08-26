// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenDynamicRubbleTypes.generated.h"

/**
 * ERubbleFractureTier
 * 
 * Size and mass classification of physical rubble debris chunks.
 */
UENUM(BlueprintType)
enum class ERubbleFractureTier : uint8
{
	FineGravel        UMETA(DisplayName = "Fine Gravel (1-25kg, Negligible Obstacle)"),
	MediumMasonry     UMETA(DisplayName = "Medium Masonry (25-150kg, Navmesh Penalty 2.0x)"),
	HeavyBoulder      UMETA(DisplayName = "Heavy Boulder (150-450kg, Impassable Choke Point)"),
	MonolithicArch    UMETA(DisplayName = "Monolithic Arch (>450kg, Structural Keystones)")
};

/**
 * EMasonryCollapseState
 * 
 * Structural integrity lifecycle of overhead stone arches and ramparts.
 */
UENUM(BlueprintType)
enum class EMasonryCollapseState : uint8
{
	StableIntact      UMETA(DisplayName = "Stable Intact (100% Integrity)"),
	StressGroaning    UMETA(DisplayName = "Stress Groaning (50%-80% Strain, Acoustic Groans)"),
	TelegraphWarning  UMETA(DisplayName = "Telegraph Warning (Dust Falling, 1.2s Impact Telegraph)"),
	CollapsingImpact  UMETA(DisplayName = "Collapsing Impact (Active Crushing Hazard)"),
	SettledDebrisPile UMETA(DisplayName = "Settled Debris Pile (Physical Obstacle Formed)")
};

/**
 * EDemolitionToolType
 * 
 * Method utilized to shatter and clear impassable rubble barriers.
 */
UENUM(BlueprintType)
enum class EDemolitionToolType : uint8
{
	None              UMETA(DisplayName = "None"),
	KaelenHeavyCleave UMETA(DisplayName = "Kaelen Parasitic Heavy Cleave (Kinetic Shatter)"),
	GarrettBreachBomb UMETA(DisplayName = "Garrett Alchemical Breaching Charge (Explosive Scatter)"),
	SerafinaThermalPurge UMETA(DisplayName = "Serafina White Flame Thermal Shock (-60% Durability)")
};

/**
 * FRubblePhysicsClusterVector
 * 
 * Physical properties and navmesh influence of a settled rubble pile.
 */
USTRUCT(BlueprintType)
struct FRubblePhysicsClusterVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float TotalMassKg = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float RubbleRadiusUU = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float NavmeshCostModifier = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	ERubbleFractureTier FractureTier = ERubbleFractureTier::MediumMasonry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	bool bIsChokePointBlocked = false;
};

/**
 * FMasonryHazardVector
 * 
 * Real-time strain and impact telemetry for collapsing overhead geometry.
 */
USTRUCT(BlueprintType)
struct FMasonryHazardVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float StructuralIntegrity01 = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float TelegraphRadiusUU = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	float CrushingImpactDamage = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Rubble")
	EMasonryCollapseState CollapseState = EMasonryCollapseState::StableIntact;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMasonryCollapseStateChanged, EMasonryCollapseState, NewState, float, StructuralIntegrity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRubbleDemolished, EDemolitionToolType, ToolUsed, float, DebrisClearedMassKg);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFallingHazardTelegraphed, const FMasonryHazardVector&, HazardData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRubbleNavmeshUpdated, float, NewCostModifier, bool, bChokePointCleared);
