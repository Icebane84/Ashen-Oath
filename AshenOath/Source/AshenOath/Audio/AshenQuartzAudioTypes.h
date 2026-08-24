// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenQuartzAudioTypes.generated.h"

/**
 * EQuartzAudioStem
 * 
 * The six interactive music stems governed by the Quartz audio clock.
 */
UENUM(BlueprintType)
enum class EQuartzAudioStem : uint8
{
	Stem01_IndustrialDrums UMETA(DisplayName = "Stem 01: Industrial Drums & Sub-Bass (Kaelen's Shadow Sickness)"),
	Stem02_NightsteelHum   UMETA(DisplayName = "Stem 02: Discordant Nightsteel Hum (Oathbringer's Whispers)"),
	Stem03_SoloViolin      UMETA(DisplayName = "Stem 03: Soaring Solo Violin & Fiddle (Serafina's Empathic Anchor)"),
	Stem04_ElectricGuitar  UMETA(DisplayName = "Stem 04: Driving Electric Guitars (Garrett's Sentinel Tactics)"),
	Stem05_PaladinChoir    UMETA(DisplayName = "Stem 05: Ethereal Paladin Choir (The Order's Gilded Illusion)"),
	Stem06_AfroPopGroove   UMETA(DisplayName = "Stem 06: Afro-Pop Syncopated Percussion (Pack Unity)")
};

/**
 * ECombatFlowState
 * 
 * Overall musical cohesion and flow state of the combat encounter.
 */
UENUM(BlueprintType)
enum class ECombatFlowState : uint8
{
	StandardTrioBaseline UMETA(DisplayName = "Standard Trio Baseline (Steady 115 BPM)"),
	SicknessDeepening    UMETA(DisplayName = "Sickness Deepening (Mounting Discordance)"),
	CrisisNearBreakdown  UMETA(DisplayName = "Crisis Near Breakdown (Severe Trauma / Desynchronization)"),
	SymbioticResonance   UMETA(DisplayName = "Symbiotic Resonance (8s Flow State & Vocal Convergence)")
};

/**
 * EAlchemicalAudioFilter
 * 
 * Active alchemical filter applied to the master audio sub-mix.
 */
UENUM(BlueprintType)
enum class EAlchemicalAudioFilter : uint8
{
	None              UMETA(DisplayName = "None (Standard Audio Spectrum)"),
	CaltropHighPass   UMETA(DisplayName = "Caltrop High-Pass (Bass Weight Cut)"),
	SmokeLowPass450Hz UMETA(DisplayName = "Smoke Low-Pass 450Hz (Sensory Deprivation Fog)"),
	TackleSideChain   UMETA(DisplayName = "Tackle Side-Chain Ducking (-24dB Slam)"),
	GloomwoodChill    UMETA(DisplayName = "Gloomwood Chemical Chill (-12 Semitones)")
};

/**
 * FQuartzStemMatrixState
 * 
 * Real-time volume gains for all 6 stems and master clock telemetry.
 */
USTRUCT(BlueprintType)
struct FQuartzStemMatrixState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float Stem01_Vol = 0.10f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float Stem02_Vol = 0.00f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float Stem03_Vol = 0.80f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float Stem04_Vol = 0.00f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float Stem05_Vol = 1.00f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float Stem06_Vol = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	float MasterBPM = 115.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	ECombatFlowState FlowState = ECombatFlowState::StandardTrioBaseline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Audio|Quartz")
	EAlchemicalAudioFilter ActiveFilter = EAlchemicalAudioFilter::None;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFlowStateChanged, ECombatFlowState, NewState, float, FlowDurationRemaining);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuartzBarDownbeat, int32, BarIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAlchemicalFilterEngaged, EAlchemicalAudioFilter, Filter, float, DurationSeconds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStemMatrixUpdated, const FQuartzStemMatrixState&, State);
