// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenBladeSanityConductorTypes.generated.h"

/**
 * EBladeHungerStage
 * 
 * Parasitic hunger progression tiers of the Oathbringer blade.
 */
UENUM(BlueprintType)
enum class EBladeHungerStage : uint8
{
	SatedDormant    UMETA(DisplayName = "Sated Dormant (0-25% Hunger, Calm)"),
	AwakenedThirst  UMETA(DisplayName = "Awakened Thirst (26-60% Hunger, +15% Dmg, Minor Whisper)"),
	VoraciousFrenzy UMETA(DisplayName = "Voracious Frenzy (61-85% Hunger, +30% Dmg, Heavy Drain)"),
	BloodMadness    UMETA(DisplayName = "Blood Madness (86-100% Hunger, +45% Dmg, Severe Sanity Collapse)")
};

/**
 * ESanityDissonanceTier
 * 
 * Psychological integrity and cognitive dissonance levels.
 */
UENUM(BlueprintType)
enum class ESanityDissonanceTier : uint8
{
	LucidHarmonic   UMETA(DisplayName = "Lucid Harmonic (75-100 Sanity, Clean Music)"),
	AnxiousEchoes   UMETA(DisplayName = "Anxious Echoes (50-74 Sanity, Stem 02 Whispers Active)"),
	ParanoidStatic  UMETA(DisplayName = "Paranoid Static (25-49 Sanity, -18dB Melodic Ducking)"),
	DeliriumMadness UMETA(DisplayName = "Delirium Madness (0-24 Sanity, Phantom Hallucinations)")
};

/**
 * EConductorAudioStemProfile
 * 
 * Active stem configuration in the Quartz 6-stem dynamic mixer.
 */
UENUM(BlueprintType)
enum class EConductorAudioStemProfile : uint8
{
	HarmonicExploration UMETA(DisplayName = "Harmonic Exploration (Stems 1,3,4,5)"),
	DissonantCombat     UMETA(DisplayName = "Dissonant Combat (Stems 1-5 Active)"),
	SymbioticFlowPurge  UMETA(DisplayName = "Symbiotic Flow Purge (Stem 2 Silenced, White Flame Stem 6 100%)")
};

/**
 * FBladeSanityHarmonicVector
 * 
 * Real-time unified state vector linking blade hunger, sanity, and audio mix levels.
 */
USTRUCT(BlueprintType)
struct FBladeSanityHarmonicVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float BladeHunger01 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	EBladeHungerStage HungerStage = EBladeHungerStage::SatedDormant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float CurrentSanity = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	ESanityDissonanceTier DissonanceTier = ESanityDissonanceTier::LucidHarmonic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float Stem02WhisperGain = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	float MelodicDuckingDb = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Convergence")
	bool bFlowStateActive = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBladeHungerSanityShifted, float, BladeHunger01, float, CurrentSanity);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDissonanceStemGainUpdated, float, Stem02Gain, float, MelodicDuckingDb);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFlowCatharsisTriggered, float, SanityRestored);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityDissonanceTierChanged, ESanityDissonanceTier, NewTier, EBladeHungerStage, HungerStage);
