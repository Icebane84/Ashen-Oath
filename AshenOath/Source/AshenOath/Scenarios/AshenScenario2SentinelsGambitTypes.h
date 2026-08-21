// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario2SentinelsGambitTypes.generated.h"

/**
 * EGarrettTrapType
 * 
 * Types of tactical traps deployable by Garrett in Scenario 2.
 */
UENUM(BlueprintType)
enum class EGarrettTrapType : uint8
{
	TensionWireSnare UMETA(DisplayName = "Tension Wire Snare (Path Interruption)"),
	PhosphorFlareMine UMETA(DisplayName = "Phosphor Flare Mine (Blind & Silhouette)"),
	SonicRavineLure UMETA(DisplayName = "Sonic Ravine Lure (Environmental Funnel)")
};

/**
 * EPathfindingDisruptionTier
 * 
 * Degree of AI navigation breakdown caused by trap triggers.
 */
UENUM(BlueprintType)
enum class EPathfindingDisruptionTier : uint8
{
	NormalNavigation UMETA(DisplayName = "Normal Navigation (Utility >= 0.70)"),
	DegradedRouting UMETA(DisplayName = "Degraded Routing (0.15 <= Utility < 0.70)"),
	CircuitBreakerTripped UMETA(DisplayName = "LAW-001 Tripped: Failed Recovery (Utility < 0.15)")
};

/**
 * FGarrettTrapPlacementData
 * 
 * Runtime data for a deployed tactical trap.
 */
USTRUCT(BlueprintType)
struct FGarrettTrapPlacementData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	FName TrapId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	EGarrettTrapType TrapType = EGarrettTrapType::TensionWireSnare;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	FVector WorldLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	float DetonationRadiusCentimeters = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	bool bIsArmed = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	bool bHasTriggered = false;
};

/**
 * FAIRavineFunnelContext
 * 
 * Diagnostic state of enemy AI navigation toward environmental hazards.
 */
USTRUCT(BlueprintType)
struct FAIRavineFunnelContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	float NavigationUtilityScore = 1.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	EPathfindingDisruptionTier DisruptionTier = EPathfindingDisruptionTier::NormalNavigation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	int32 EnemiesFunneledIntoRavine = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario2")
	bool bStealthMaintained = true;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTrapDeployed, const FName&, TrapId, EGarrettTrapType, Type);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPathfindingDisrupted, EPathfindingDisruptionTier, DisruptionTier, float, UtilityScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnemyFunneledToHazard, const FName&, EnemyId, int32, TotalFunneled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSentinelsGambitCompleted, bool, bSilentEscape);
