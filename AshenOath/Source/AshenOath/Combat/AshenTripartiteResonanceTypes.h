// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenTripartiteResonanceTypes.generated.h"

// -----------------------------------------------------------------------------------
// TRIPARTITE RESONANCE & FINISHER ENUMS (TRIO-SPEC-061)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class ETripartiteComboPhase : uint8
{
	Inactive            UMETA(DisplayName = "Inactive (Neutral State)"),
	Step1_KaelenCleave  UMETA(DisplayName = "Step 1: Kaelen Heavy Stagger / Cleave"),
	Step2_GarrettSnare  UMETA(DisplayName = "Step 2: Garrett Tactical Wire Snare"),
	Step3_SerafinaBurst UMETA(DisplayName = "Step 3: Serafina Holy Ward Burst"),
	FinisherReady       UMETA(DisplayName = "Finisher Ready (3-Way Harmonized Alignment)")
};

UENUM(BlueprintType)
enum class EHarmonizedFinisherTier : uint8
{
	StandardTripartite  UMETA(DisplayName = "Standard Tripartite Finisher (3.0x Damage)"),
	RadiantCatharsis    UMETA(DisplayName = "Radiant Catharsis Finisher (3.5x Damage + 30% Dysregulation Cleansed)"),
	TranscendentOath    UMETA(DisplayName = "Transcendent Oath Finisher (4.5x Damage + Trust Surge)")
};

// -----------------------------------------------------------------------------------
// TRIPARTITE RESONANCE & FINISHER STRUCTS
// -----------------------------------------------------------------------------------

/**
 * Real-time state of the 3-step Tripartite Combo progression.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FTripartiteComboState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Trio")
	FString ComboSessionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Trio")
	ETripartiteComboPhase CurrentPhase = ETripartiteComboPhase::Inactive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Trio")
	float RemainingWindowSeconds = 0.0f; // Max 2.5s

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Trio")
	bool bGarrettInProximity = false; // <= 800uu

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Trio")
	bool bSerafinaInProximity = false; // <= 800uu

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Trio")
	EHarmonizedFinisherTier FinisherTier = EHarmonizedFinisherTier::StandardTripartite;
};

/**
 * DualSense haptic resonance profile tracking 60 BPM rhythm (1.0s base pulse).
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FHapticResonanceProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float PulseFrequencyHz = 1.0f; // 60 BPM = 1.0 Hz

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float LeftTriggerResistance = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float RightTriggerResistance = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Haptics")
	float VibrationIntensity = 0.75f;
};

// -----------------------------------------------------------------------------------
// MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTripartiteComboPhaseChanged, const FTripartiteComboState&, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHarmonizedFinisherExecuted, EHarmonizedFinisherTier, Tier, float, TotalDamage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHapticResonancePulsed, const FHapticResonanceProfile&, Profile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFellowshipCatharsisTriggered, float, TrustGained, float, DysregulationPurged);
