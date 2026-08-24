// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenScenario10Types.generated.h"

/**
 * EZenithConsequenceEnding
 * 
 * The 4 Grand Consequence Endings resolved at the Sovereign Convergence.
 */
UENUM(BlueprintType)
enum class EZenithConsequenceEnding : uint8
{
	RadiantTransfiguration  UMETA(DisplayName = "Radiant Transfiguration (Apotheosis Unification - High Trust / Low Debt)"),
	CauterizedHegemony      UMETA(DisplayName = "The Cauterized Hegemony (Iron Will - Martial Dominance)"),
	BleedingFracture        UMETA(DisplayName = "The Bleeding Fracture (Relational Dissociation - Low Trust / High Debt)"),
	AshenEclipse            UMETA(DisplayName = "The Ashen Eclipse (Complete Void Integration - Max Integration Debt)")
};

/**
 * EApotheosisResonanceStage
 * 
 * The 3 stages of Tripartite Apotheosis resonance buildup.
 */
UENUM(BlueprintType)
enum class EApotheosisResonanceStage : uint8
{
	DormantLatent       UMETA(DisplayName = "Dormant Latent Alignment"),
	HarmonicBuildup     UMETA(DisplayName = "Harmonic Buildup (Solfeggio Triad Active)"),
	SovereignApotheosis UMETA(DisplayName = "Sovereign Apotheosis (Unified Tri-Soul Entity)")
};

/**
 * ETripartiteAlignmentTier
 * 
 * Relational attunement tier of the party at the Grand Zenith.
 */
UENUM(BlueprintType)
enum class ETripartiteAlignmentTier : uint8
{
	FracturedDiscord    UMETA(DisplayName = "Fractured Discord (<40% Trust)"),
	TemperedAlliance    UMETA(DisplayName = "Tempered Alliance (40%-75% Trust)"),
	SovereignTriad      UMETA(DisplayName = "Sovereign Triad (>75% Trust)")
};

/**
 * FZenithConvergenceVector
 * 
 * Telemetry and consequence resolution vector in Scenario 10.
 */
USTRUCT(BlueprintType)
struct FZenithConvergenceVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	float ApotheosisResonance01 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	float CombinedTrustScore01 = 0.85f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	float IntegrationDebt01 = 0.20f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	float DamageMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	EApotheosisResonanceStage ResonanceStage = EApotheosisResonanceStage::DormantLatent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	EZenithConsequenceEnding ResolvedEnding = EZenithConsequenceEnding::RadiantTransfiguration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Scenario10")
	bool bConsequenceResolved = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnApotheosisStageChanged, EApotheosisResonanceStage, NewStage, float, Resonance01);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConsequenceEndingResolved, EZenithConsequenceEnding, Ending, FText, EpilogueSummary);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTripartiteFinisherExecuted, float, TotalDamage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGrandZenithAuraIgnited, float, AuraRadiusUU);
