// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenBleedingWaystationTypes.generated.h"

/**
 * EWaystationRunMode
 * 
 * The 4 distinct systemic runs of The Bleeding Waystation 7-minute vertical slice.
 */
UENUM(BlueprintType)
enum class EWaystationRunMode : uint8
{
	RunA_ShadowHarvest      UMETA(DisplayName = "Run A: The Path of Brutal Utility (Shadow Harvest)"),
	RunB_PureGrace          UMETA(DisplayName = "Run B: The Path of Grace (Merciful Release)"),
	RunC_TheSpiral          UMETA(DisplayName = "Run C: The Spiral (High Integration Debt Panic)"),
	RunD_AvoidantMercy      UMETA(DisplayName = "Run D: Avoidant Mercy (Dissociated Restraint)")
};

/**
 * EScoutCatalystDecision
 * 
 * The immediate decision made regarding the pinned Order scout.
 */
UENUM(BlueprintType)
enum class EScoutCatalystDecision : uint8
{
	HarvestResidualTaint UMETA(DisplayName = "Harvest Residual Taint"),
	MercifulCleanDeath   UMETA(DisplayName = "Merciful Clean Death & Burial"),
	DesperateStabilize   UMETA(DisplayName = "Desperate Stabilization Attempt"),
	PanicInvoluntarySlain UMETA(DisplayName = "Slain in Involuntary Panic Flash")
};

/**
 * EGarrettDualWieldBenchmarkResponse
 * 
 * Garrett's dual-wield sentinel reaction during the universal 'Knocked to One Knee' benchmark.
 */
UENUM(BlueprintType)
enum class EGarrettDualWieldBenchmarkResponse : uint8
{
	TwinBladeXLockDeflect UMETA(DisplayName = "Twin-Blade X-Lock Cross-Parry Deflect"),
	DaggerFlankPeel       UMETA(DisplayName = "Dagger Flank Throw & Aggro Peel"),
	DefensiveBladeAbort   UMETA(DisplayName = "Defensive Blade Cross Against Kaelen (Abort)"),
	HesitantGuardedHold   UMETA(DisplayName = "Hesitant Guarded Stance (Distant Hold)")
};

/**
 * ESerafinaSupportState
 * 
 * Serafina's support posture in the 90-second combat crucible.
 */
UENUM(BlueprintType)
enum class ESerafinaSupportState : uint8
{
	InstantTransferenceAura UMETA(DisplayName = "Instant Transference Aura (0ms Delay)"),
	HesitantDelayedBuff     UMETA(DisplayName = "Hesitant Delayed Buff (300ms Delay)"),
	TerrifiedSeveredAura    UMETA(DisplayName = "Terrified Severed Connection (600ms Panic Lock)"),
	TentativeGuardedAura    UMETA(DisplayName = "Tentative Guarded Aura (150ms Delay)")
};

/**
 * FWaystationRunContext
 * 
 * Runtime diagnostic telemetry for the active waystation run.
 */
USTRUCT(BlueprintType)
struct FWaystationRunContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Waystation")
	EWaystationRunMode RunMode = EWaystationRunMode::RunA_ShadowHarvest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Waystation")
	EScoutCatalystDecision ScoutDecision = EScoutCatalystDecision::HarvestResidualTaint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Waystation")
	float SerafinaFormationDistanceUU = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Waystation")
	float StateTreeHesitationLatencyMS = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Waystation")
	EGarrettDualWieldBenchmarkResponse GarrettResponse = EGarrettDualWieldBenchmarkResponse::DaggerFlankPeel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Waystation")
	float IntegrationDebt = 0.20f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWaystationRunSelected, EWaystationRunMode, RunMode, EScoutCatalystDecision, Decision);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKnockedToKneeBenchmarkTriggered, EGarrettDualWieldBenchmarkResponse, GarrettAction, ESerafinaSupportState, SerafinaAction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFormationSpacingShifted, float, SerafinaDistance, float, GarrettDistance);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCrucibleCombatCompleted, bool, bZeroCompanionsDowned);
