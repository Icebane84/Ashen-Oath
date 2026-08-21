// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario1CauterizedHeartTypes.generated.h"

/**
 * EMalakorBossPhase
 * 
 * Defines Brother Malakor's encounter phase in Oakhaven Chapel.
 */
UENUM(BlueprintType)
enum class EMalakorBossPhase : uint8
{
	Phase1_InquisitorSmash UMETA(DisplayName = "Phase 1: Inquisitor Void Smash"),
	Phase2_PuristZealot UMETA(DisplayName = "Phase 2: Purist Zealot & Null Zone"),
	Phase3_AbominationCascade UMETA(DisplayName = "Phase 3: Shattered Cage Abomination")
};

/**
 * EReluctantKnifeEthos
 * 
 * Evaluates Elder Valerius's psychological stance during confrontation.
 */
UENUM(BlueprintType)
enum class EReluctantKnifeEthos : uint8
{
	ControlledMitigation UMETA(DisplayName = "Controlled Mitigation (Exhausted Strategy)"),
	DesperateContainment UMETA(DisplayName = "Desperate Containment (Heavy Sacrifice)"),
	HardenedResignation UMETA(DisplayName = "Hardened Resignation (The Burden Borne)")
};

/**
 * FMalakorEncounterState
 * 
 * Live runtime state of the Brother Malakor boss battle.
 */
USTRUCT(BlueprintType)
struct FMalakorEncounterState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	EMalakorBossPhase CurrentPhase = EMalakorBossPhase::Phase1_InquisitorSmash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	float BossHealthPercent = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	float RitualInterruptionCount = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	bool bNullZoneActive = false;
};

/**
 * FClarityOfHeartRitualContext
 * 
 * State of the Clarity of Heart purification ritual at the chapel altar.
 */
USTRUCT(BlueprintType)
struct FClarityOfHeartRitualContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	float RitualProgressPercent = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	float AmberFlameIntensity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	bool bIsInterrupted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario1")
	float AccumulatedDebtSpike = 0.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMalakorPhaseShifted, EMalakorBossPhase, NewPhase, float, HealthPercent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRitualInterrupted, float, ProgressAtInterrupt, float, DebtSpikeAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReluctantKnifeEvaluated, EReluctantKnifeEthos, Ethos, float, ExhaustionScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOakhavenChapelCleared, bool, bRitualSuccessful);
