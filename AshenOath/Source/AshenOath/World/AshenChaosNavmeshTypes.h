// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenChaosNavmeshTypes.generated.h"

/**
 * EChaosFractureSeverity
 * 
 * Structural fracture intensity of Chaos geometry collections.
 */
UENUM(BlueprintType)
enum class EChaosFractureSeverity : uint8
{
	IntactSolid      UMETA(DisplayName = "Intact Solid (100% Integrity)"),
	SurfaceFissure   UMETA(DisplayName = "Surface Fissure (Stress Cracks)"),
	PartialCollapse  UMETA(DisplayName = "Partial Collapse (Heavy Rubble Fall)"),
	TotalDemolition  UMETA(DisplayName = "Total Demolition (Navmesh Choke Blocked)")
};

/**
 * ENavmeshObstructionState
 * 
 * Dynamic status of the Recast navigation mesh beneath debris.
 */
UENUM(BlueprintType)
enum class ENavmeshObstructionState : uint8
{
	ClearPath           UMETA(DisplayName = "Clear Unobstructed Path"),
	VaultableLowDebris  UMETA(DisplayName = "Vaultable Low Debris (<120uu)"),
	BlockedHighRubble   UMETA(DisplayName = "Blocked High Rubble (>120uu - Detour Required)"),
	PulverizedCleared   UMETA(DisplayName = "Pulverized & Cleared by Kinetic Cleave")
};

/**
 * EStructuralMaterialType
 * 
 * Material classification for acoustic impulse and debris mass physics.
 */
UENUM(BlueprintType)
enum class EStructuralMaterialType : uint8
{
	GraniteStone   UMETA(DisplayName = "Granite Stone (Hardness 0.85, High Density)"),
	TimberSupport  UMETA(DisplayName = "Timber Support (Hardness 0.40, Splinter Sound)"),
	RunicBasalt    UMETA(DisplayName = "Runic Basalt (Hardness 1.00, Solfeggio Hum)")
};

/**
 * FChaosDebrisClusterVector
 * 
 * Telemetry and spatial bounding data for a dynamic debris cluster on the navmesh.
 */
USTRUCT(BlueprintType)
struct FChaosDebrisClusterVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	EChaosFractureSeverity FractureSeverity = EChaosFractureSeverity::IntactSolid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	ENavmeshObstructionState ObstructionState = ENavmeshObstructionState::ClearPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	EStructuralMaterialType MaterialType = EStructuralMaterialType::GraniteStone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	FVector ClusterLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	float TotalDebrisMassKg = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	float NavmeshBlockingRadiusUU = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	float AcousticImpulseJoules = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Chaos")
	bool bRequiresDetour = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnChaosPillarFractured, EChaosFractureSeverity, Severity, FVector, FractureLocation, float, ImpactJoules);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNavmeshObstructionChanged, FVector, DebrisLocation, ENavmeshObstructionState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChaosSpatialAudioImpulse, FVector, SoundOrigin, float, FrequencyHz);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDebrisClusterCleared, FVector, ClearedLocation);
