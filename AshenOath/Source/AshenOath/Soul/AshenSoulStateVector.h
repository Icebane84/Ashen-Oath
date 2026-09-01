// AshenSoulStateVector.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) -- FSoulStateVector MVSC Data Contract
#pragma once

#include "CoreMinimal.h"
#include "AshenSoulStateVector.generated.h"

// ---------------------------------------------------------------------------
// INTERPRETIVE LENS
// The philosophical filter applied during Soul Compilation (ApplyInterpretiveFilter).
// ---------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EInterpretiveLens : uint8
{
	Accountability  UMETA(DisplayName = "Accountability"),
	Grace           UMETA(DisplayName = "Grace / Compassion"),
	Utility         UMETA(DisplayName = "Utility"),
	Nihilism        UMETA(DisplayName = "Nihilism / Spite"),
	Penance         UMETA(DisplayName = "Penance"),
};

// ---------------------------------------------------------------------------
// BEHAVIORAL PROFILE ENUMS
// Semantic abstraction over raw floats. Downstream systems (AnimBP, Audio,
// AI, Shaders) query these discrete enums -- never raw FSoulStateVector floats.
// ---------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EStanceProfile : uint8
{
	Hunched_Guarded     UMETA(DisplayName = "Hunched / Guarded"),
	Balanced_Steady     UMETA(DisplayName = "Balanced / Steady"),
	Upright_Grounded    UMETA(DisplayName = "Upright / Grounded"),
};

UENUM(BlueprintType)
enum class EEmpathicProfile : uint8
{
	Burned_Out          UMETA(DisplayName = "Burned Out"),
	Resonant_Attuned    UMETA(DisplayName = "Resonant / Attuned"),
	Radiant_Shield      UMETA(DisplayName = "Radiant Shield"),
};

UENUM(BlueprintType)
enum class ETacticalProfile : uint8
{
	Cynical_Isolated        UMETA(DisplayName = "Cynical / Isolated"),
	Calculated_Pragmatic    UMETA(DisplayName = "Calculated / Pragmatic"),
	Unshakeable_Anchor      UMETA(DisplayName = "Unshakeable Anchor"),
};

// ---------------------------------------------------------------------------
// INTEGRATION DEBT STAGE
// 4-stage escalation pipeline for unprocessed psychological pressure.
// Evaluated by FSoulStateVector::GetDebtStage() -- single location for thresholds.
// ---------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EIntegrationDebtStage : uint8
{
	// 0.0 – 0.49: Imprints buffer silently. No visible effect.
	Dormant         UMETA(DisplayName = "Dormant"),

	// 0.5 – 0.74: Audio echoes spill; edge desaturation begins.
	MemoryBleed     UMETA(DisplayName = "Memory Bleed"),

	// 0.75 – 0.99: Parry windows narrow 15%; companion pathfinding delays; HUD flickers.
	RuntimeNoise    UMETA(DisplayName = "Runtime Noise"),

	// 1.0: Forced involuntary Mindscape entry with structural handicaps.
	ForcedCollapse  UMETA(DisplayName = "Forced Collapse"),
};

// ---------------------------------------------------------------------------
// BEHAVIORAL PROFILE
// Evaluated cache written by CompileIdentity(). Consumed by all subsystems.
// 3 bytes flat -- safe to copy on the stack every invalidation tick.
// ---------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ASHENOATH_API FBehavioralProfile
{
	GENERATED_BODY()

	// Kaelen's physical & emotional stance. Drives AnimBP idle blend tree.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Profile")
	EStanceProfile Stance = EStanceProfile::Balanced_Steady;

	// Serafina's empathic resonance state. Drives Dialogue Engine node availability.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Profile")
	EEmpathicProfile Empathic = EEmpathicProfile::Resonant_Attuned;

	// Garrett's tactical disposition. Drives AI pathfinding offsets & cover selection.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Profile")
	ETacticalProfile Tactical = ETacticalProfile::Calculated_Pragmatic;
};

// ---------------------------------------------------------------------------
// FSoulStateVector -- MINIMUM VIABLE SOUL CONSTELLATION (MVSC)
// ENGINE-SPEC-001 (DEFINITIVE CANON) Section 3 / AOP-EXEC-001 Part I.
//
// AXIOM I:  SINGLE SOURCE OF TRUTH. Published by USoulConstellationSubsystem only.
// AXIOM III: Every frame rendered is a query against this StateVector via ActiveProfile.
//
// Memory contract: < 128 bytes for cache-line safety during OnStateVectorInvalidated.
// ---------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ASHENOATH_API FSoulStateVector
{
	GENERATED_BODY()

	// ---- Identity Triad (0.0 – 1.0) ----------------------------------------
	// Physical & emotional stability. Drives Stance Profile & AnimBP sword drag weight.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Identity")
	float Resolve = 1.0f;

	// Shadow Mark saturation. Drives CorruptionAmount MPC scalar & Oathbringer emissive.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Identity")
	float Corruption = 0.0f;

	// Self-sacrificing tendency. Drives Dialogue tone & Whispering Wind audio density.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Identity")
	float Isolation = 0.0f;

	// ---- Relational Tethers (0.0 – 1.0) ------------------------------------
	// Tactical cohesion & spatial offset driver for Garrett's AI tree.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Relational")
	float GarrettTrust = 0.5f;

	// Empathic resonance & Transference efficiency for Serafina's AI tree.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Relational")
	float SerafinaTrust = 0.5f;

	// ---- Systemic Pressure (0.0 – 1.0) -------------------------------------
	// Accumulated unprocessed imprints. At 1.0 forces involuntary Mindscape collapse.
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Pressure")
	float IntegrationDebt = 0.0f;

	// ---- Interpretive State ------------------------------------------------
	UPROPERTY(BlueprintReadOnly, Category = "Soul Constellation | Lens")
	EInterpretiveLens PrimaryLens = EInterpretiveLens::Accountability;

	// ---- Inline Helpers ----------------------------------------------------

	/** Returns the Integration Debt escalation stage without duplicating threshold logic. */
	FORCEINLINE EIntegrationDebtStage GetDebtStage() const
	{
		if (IntegrationDebt >= 1.0f)  return EIntegrationDebtStage::ForcedCollapse;
		if (IntegrationDebt >= 0.75f) return EIntegrationDebtStage::RuntimeNoise;
		if (IntegrationDebt >= 0.5f)  return EIntegrationDebtStage::MemoryBleed;
		return EIntegrationDebtStage::Dormant;
	}

	/** Returns true when both companions are in sync and Kaelen is stable. */
	FORCEINLINE bool IsResonanceSyncActive() const
	{
		return FMath::Abs(SerafinaTrust - GarrettTrust) < 0.15f
			&& SerafinaTrust > 0.4f
			&& GarrettTrust  > 0.4f
			&& Resolve       > 0.5f;
	}
};
