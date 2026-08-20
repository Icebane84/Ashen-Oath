// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AshenMacroSystemicContractTypes.generated.h"

// -----------------------------------------------------------------------------------
// CANONICAL ENUMERATIONS (CONTRACT-SPEC-051 Iteration VII)
// -----------------------------------------------------------------------------------

UENUM(BlueprintType)
enum class EOntologicalLens : uint8
{
	Uncompiled  UMETA(DisplayName = "Uncompiled / Raw Memory"),
	Defiance    UMETA(DisplayName = "Defiance ('I will endure this myself')"),
	Grace       UMETA(DisplayName = "Grace ('I will let someone share this burden')"),
	Wrath       UMETA(DisplayName = "Wrath ('I will make someone else pay for this')")
};

UENUM(BlueprintType)
enum class ETriggerResistanceSource : uint8
{
	DialogueWillStruggle = 0 UMETA(DisplayName = "Dialogue Will Struggle (Priority 1 — Modal 2.0s squeeze, absolute precedence)"),
	CombatStagger        = 1 UMETA(DisplayName = "Combat Stagger (Priority 2 — 50% baseline -> instant 0% on poise-break)"),
	AmbientSomatic       = 2 UMETA(DisplayName = "Ambient Somatic (Priority 3 — Continuous background, derived from Phi_internal)")
};

UENUM(BlueprintType)
enum class EMemoryImprintType : uint8
{
	CombatLoss,
	CompanionConflict,
	CompanionRescue,
	SyncFinisherExecuted,
	Betrayal,
	Sacrifice,
	Retreat,
	WillTrialFailure,
	WillTrialBreakthrough
};

UENUM(BlueprintType)
enum class EExperienceContext : uint8
{
	Exploration,
	Combat,
	Dialogue,
	CampfireRest,
	HeartstoneCrucible
};

UENUM(BlueprintType)
enum class EWillContext : uint8
{
	DialogueGraceSqueeze,
	StaggerPostureDuel,
	TransferenceSomaticHold,
	CataclysmSanctification
};

UENUM(BlueprintType)
enum class EWillTrialResult : uint8
{
	Success,
	ReleasedEarly,
	TimedOut,
	Cancelled,
	AccessibilityAlternateInput
};

UENUM(BlueprintType)
enum class ESyncFinisherType : uint8
{
	SoloMartyrStrike,
	TripartiteResonantCleave,
	WhitePyreDisintegration
};

UENUM(BlueprintType)
enum class EResonanceBand : uint8
{
	Discordant   UMETA(DisplayName = "Discordant (TrioResonance < 0.35)"),
	Attuned      UMETA(DisplayName = "Attuned (0.35 <= TrioResonance < 0.75)"),
	Synchronized UMETA(DisplayName = "Synchronized (TrioResonance >= 0.75)")
};

// -----------------------------------------------------------------------------------
// CANONICAL UTILITY FUNCTIONS
// -----------------------------------------------------------------------------------

namespace AshenContractUtils
{
	FORCEINLINE float GetLensDistance(EOntologicalLens A, EOntologicalLens B)
	{
		if (A == B) return 0.0f;
		if (A == EOntologicalLens::Uncompiled || B == EOntologicalLens::Uncompiled) return 0.0f;
		return 1.0f;
	}

	FORCEINLINE int32 GetDysregulationStage(float N)
	{
		if (N >= 1.0f)  return 4;
		if (N >= 0.75f) return 3;
		if (N >= 0.50f) return 2;
		return 1;
	}
}

// -----------------------------------------------------------------------------------
// CANONICAL DATA PAYLOADS
// -----------------------------------------------------------------------------------

/**
 * Layer A: Canonical Persistent Soul State (128-bit Identity Vector).
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCanonicalSoulStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	float IntegrationDebt = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	float AccumulatedDysregulation = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	float Resolve = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	float Corruption = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	EOntologicalLens DominantLens = EOntologicalLens::Defiance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	EOntologicalLens PreviousDominantLens = EOntologicalLens::Uncompiled;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Soul")
	int64 StateVersion = 1;
};

/**
 * Layer A: Canonical Persistent Relational Matrix (Pairwise Companion Dynamics).
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCanonicalRelationalMatrix
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Relational")
	float Trust_Serafina = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Relational")
	float Burnout_Serafina = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Relational")
	float Trust_Garrett = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Relational")
	float Fatigue_Garrett = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Relational")
	float TrioResonance = 0.5f;

	FORCEINLINE EResonanceBand GetResonanceBand() const
	{
		if (TrioResonance >= 0.75f) return EResonanceBand::Synchronized;
		if (TrioResonance >= 0.35f) return EResonanceBand::Attuned;
		return EResonanceBand::Discordant;
	}
};

/**
 * Layer A: The Archaeological Memory Graph Payload.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FMemoryImprintPayload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	FGuid ImprintId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	FGuid OriginTransactionId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	FName MemorySiteId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	FName EncounterId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	EMemoryImprintType ImprintType = EMemoryImprintType::CombatLoss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	float EmotionalMagnitude = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	float ThreatMagnitude = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	float RelationalSignificance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	float IdentitySignificance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	FGameplayTagContainer ContextTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	double GameTimeSeconds = 0.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	TArray<FGuid> RelatedImprintIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	bool bHasBeenCompiledAtHeartstone = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Memory")
	EOntologicalLens InterpretedLens = EOntologicalLens::Uncompiled;
};

/**
 * Layer B: Runtime Contextual Pressure State.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FContextualPressureState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Context")
	EExperienceContext ExperienceContext = EExperienceContext::Exploration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Context")
	float ImmediateThreatIntensity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Context")
	float PhysicalExhaustion = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Context")
	float CompanionProximityFactor = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Context")
	bool bCompanionSupportPresent = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Context")
	bool bInSanctuarySafeZone = false;
};

/**
 * Layer C: Derived Internal Somatic State.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FSomaticState
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	FGuid SourceTransactionId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	int64 SourceStateVersion = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	float InternalFriction = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	float RelationalFlow = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	float ParasitePressure = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	float WillCapacity = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatic")
	float IsolationPressure = 0.0f;
};

/**
 * Layer C: Per-Action Somatic Will Resistance.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FActionCongruenceResult
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Congruence")
	FGuid SourceTransactionId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Congruence")
	int64 SourceStateVersion = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Congruence")
	FGameplayTag IntendedActionTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Congruence")
	float MemorySeverity = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Congruence")
	float ActiveCompanionTrust = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Congruence")
	float ResistanceSomatic = 0.0f;
};

/**
 * Layer D: Universal Expression Intent (Hardware-Agnostic).
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FSomaticExpressionIntent
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	FGuid SourceTransactionId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	int64 SourceStateVersion = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	ETriggerResistanceSource ActiveResistanceSource = ETriggerResistanceSource::AmbientSomatic;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	float InputResistanceIntent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	float AudioIntrusionIntent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	float HapticTremorIntent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	float VisualInstabilityIntent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	float JournalDegradationIntent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Intent")
	float CompanionSupportExpression = 0.0f;
};

/**
 * Layer E: Soul Compilation Delta Result Payload.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FCompilationResult
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	FGuid CompilationId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	TArray<FGuid> SourceImprintIds;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float IntegrationDebtBefore = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float IntegrationDebtAfter = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float ResolveDelta = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float CorruptionDelta = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float TrustGarrettDelta = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float TrustSerafinaDelta = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float TrioResonanceDelta = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	float LensShiftMagnitude = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	EOntologicalLens SelectedLens = EOntologicalLens::Grace;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	FGameplayTagContainer ResolutionTags;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	int64 SourceStateVersion = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Compilation")
	int64 ResultStateVersion = 0;
};

/**
 * The Salience Gate Budget (Rate Limiter & Threshold Filter).
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FSalienceBudget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Salience")
	float SalienceThreshold = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Salience")
	float CriticalBypassThreshold = 0.50f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Salience")
	float MinCooldownSeconds = 3.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Salience")
	double LastExpressionTimestamp = 0.0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Salience")
	float LastDispatchedFriction = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Salience")
	float LastDispatchedFlow = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Salience")
	float LastDispatchedParasite = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Salience")
	float LastDispatchedWill = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Salience")
	float LastDispatchedIsolation = 0.0f;
};

/**
 * Immutable Session Snapshot for Trials of Will.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FWillTrialSessionSnapshot
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Will")
	FGuid InitialTransactionId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Will")
	int64 InitialStateVersion = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Will")
	double StartTimestamp = 0.0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Will")
	float SnapshotResistanceSomatic = 0.0f;
};

// -----------------------------------------------------------------------------------
// MASTER LIFECYCLE MULTICAST DELEGATES
// -----------------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTraumaImprintCreated, const FMemoryImprintPayload&, Payload);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoulCompiled, const FCompilationResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCanonicalStateCommitted, const FCanonicalSoulStateVector&, SoulState, const FCanonicalRelationalMatrix&, RelationalState, int64, StateVersion, FGuid, TransactionId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSomaticStateUpdated, const FSomaticState&, SomaticState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActionCongruenceEvaluated, const FActionCongruenceResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExpressionIntentDispatched, const FSomaticExpressionIntent&, Intent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTrialOfWillTriggered, EWillContext, Context, float, WindowDuration);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnTrialOfWillResolved, EWillContext, Context, EWillTrialResult, Result, float, CompletionRatio, FGuid, SourceTransactionId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTripartiteSyncExecuted, ESyncFinisherType, FinisherType);
