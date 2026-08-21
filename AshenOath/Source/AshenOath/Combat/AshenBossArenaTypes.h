// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenBossArenaTypes.generated.h"

// -----------------------------------------------------------------------------------
// BOSS ENCOUNTER & ARENA ENUMS (ARENA-SPEC-063)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EBossEncounterPhase : uint8
{
	Phase1_Guardian         UMETA(DisplayName = "Phase 1: Sanctuary Guardian (100%-65% HP)"),
	Phase2_NightsteelTitan  UMETA(DisplayName = "Phase 2: Corrupted Nightsteel Titan (65%-30% HP)"),
	Phase3_UmbralMeltdown   UMETA(DisplayName = "Phase 3: Umbral Cataclysm Meltdown (<30% HP)"),
	Defeated                UMETA(DisplayName = "Boss Defeated")
};

UENUM(BlueprintType)
enum class ECompanionCrisisState : uint8
{
	None             UMETA(DisplayName = "No Crisis Active"),
	TargetedForPin   UMETA(DisplayName = "Companion Targeted For Pinning Strike"),
	PinnedInExecution UMETA(DisplayName = "Companion Pinned (3.0s Decision Window)"),
	RescuedByTransference UMETA(DisplayName = "Companion Rescued via Empathic Transference"),
	RescuedByKineticCounter UMETA(DisplayName = "Companion Rescued via Tripartite Kinetic Stagger"),
	WoundedFallback  UMETA(DisplayName = "Intervention Failed: Companion Wounded & Silenced")
};

// -----------------------------------------------------------------------------------
// BOSS ENCOUNTER & ARENA STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Real-time state of the Sundered Sanctuary boss encounter.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FBossArenaState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	FString EncounterId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	EBossEncounterPhase CurrentPhase = EBossEncounterPhase::Phase1_Guardian;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float BossHealthPercent = 1.0f; // 100%

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	int32 IntactPillarsCount = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float ArenaObstructionScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	bool bUmbralMeltdownActive = false;
};

/**
 * Tactical context for a companion pinning crisis event.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCompanionCrisisContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	FName PinnedCompanionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	ECompanionCrisisState CrisisState = ECompanionCrisisState::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float RemainingDecisionWindowSeconds = 0.0f; // 3.0s Max

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float TrustRewardOnRescue = 0.20f;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBossPhaseShifted, EBossEncounterPhase, NewPhase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArenaPillarSundered, int32, PillarIndex, float, ArenaObstruction);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompanionCrisisTriggered, const FCompanionCrisisContext&, Context);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionCrisisResolved, ECompanionCrisisState, Outcome, float, TrustDelta);
