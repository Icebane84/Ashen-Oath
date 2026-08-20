// AshenOath_ImprintBufferComponent.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON)
// The session-volatile buffer of unresolved Psychological Imprints.
// Cleared on death before Heartstone. Consumed by InvokeIntegration().
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVector.h"
#include "AshenOath_ImprintBufferComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAshenImprint, Log, All);

// ---------------------------------------------------------------------------
// IMPRINT TYPE
// The six canonical event classes from ENGINE-SPEC-001 Section 1.
// ---------------------------------------------------------------------------
UENUM(BlueprintType)
enum class EImprintType : uint8
{
	Combat          UMETA(DisplayName = "Combat"),
	Relationship    UMETA(DisplayName = "Relationship"),
	Memory          UMETA(DisplayName = "Memory"),
	Environmental   UMETA(DisplayName = "Environmental"),
	Oath            UMETA(DisplayName = "Oath"),
	Identity        UMETA(DisplayName = "Identity"),
};

// ---------------------------------------------------------------------------
// PSYCHOLOGICAL IMPRINT
// A single unresolved experiential record. Contiguous array storage --
// no pointer-chasing on high-frequency combat ticks.
// ---------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ASHENOATH_API FPsychologicalImprint
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Imprint")
	EImprintType Type = EImprintType::Combat;

	// Relative weight (0.0 – 1.0). Heavier imprints drive stronger Mindscape enemies.
	UPROPERTY(BlueprintReadOnly, Category = "Imprint")
	float Weight = 0.0f;

	// World time at imprint creation. Used for debt decay calculations.
	UPROPERTY(BlueprintReadOnly, Category = "Imprint")
	float Timestamp = 0.0f;
};

// ---------------------------------------------------------------------------
// DELEGATE: Debt stage transition notification.
// Fired when IntegrationDebt crosses a stage boundary.
// ---------------------------------------------------------------------------
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
	FOnDebtStageChanged,
	EIntegrationDebtStage, PreviousStage,
	EIntegrationDebtStage, NewStage
);

/**
 * @class UAshenOath_ImprintBufferComponent
 * @brief Session-volatile psychological pressure accumulator on AAshenCombatCharacter.
 *
 * Responsibilities:
 *  - Stores raw FPsychologicalImprint records in a pre-reserved contiguous TArray.
 *  - Tracks IntegrationDebt (0.0 – 1.0) and broadcasts stage transitions.
 *  - Cleared by DecayBuffer() on death before Heartstone (no persistent state change).
 *  - Consumed and cleared by ConsumeBuffer() during InvokeIntegration().
 */
UCLASS(ClassGroup = (AshenOath), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_ImprintBufferComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_ImprintBufferComponent();

	// --- Public API ---------------------------------------------------------

	/** Add a new imprint to the buffer. Updates IntegrationDebt and fires stage delegate. */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	void AddImprint(EImprintType Type, float Weight);

	/**
	 * Decay buffer on death before Heartstone.
	 * Wipes the imprint array without touching the persistent StateVector.
	 * IntegrationDebt reduced by DecayOnDeathFraction.
	 */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	void DecayBuffer();

	/**
	 * Consume and clear the full buffer during InvokeIntegration().
	 * Returns a copy of all pending imprints for CompileIdentity() to evaluate.
	 * After this call the buffer is empty and IntegrationDebt is 0.
	 */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	TArray<FPsychologicalImprint> ConsumeBuffer();

	/** Returns the current raw IntegrationDebt value (0.0 – 1.0). */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	float GetIntegrationDebt() const { return IntegrationDebt; }

	/** Returns the current escalation stage. Delegates may fire whenever this changes. */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	EIntegrationDebtStage GetDebtStage() const;

	/** Returns the heaviest imprint type in the current buffer (used to pick Mindscape enemy). */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	EImprintType GetDominantImprintType() const;

	/** Returns the total number of buffered imprints. */
	UFUNCTION(BlueprintCallable, Category = "Soul Constellation | Imprint Buffer")
	int32 GetImprintCount() const { return ImprintBuffer.Num(); }

	// --- Delegates ----------------------------------------------------------

	/** Broadcast when IntegrationDebt crosses a stage threshold. */
	UPROPERTY(BlueprintAssignable, Category = "Soul Constellation | Imprint Buffer")
	FOnDebtStageChanged OnDebtStageChanged;

protected:
	virtual void BeginPlay() override;

private:
	// Pre-reserved to avoid per-frame allocation during high-intensity combat.
	UPROPERTY(Transient)
	TArray<FPsychologicalImprint> ImprintBuffer;

	// Raw debt value. Clamped [0, 1]. Written by AddImprint() / DecayBuffer() / ConsumeBuffer().
	UPROPERTY(Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"),
		Category = "Soul Constellation | Imprint Buffer")
	float IntegrationDebt = 0.0f;

	// Fraction of IntegrationDebt removed on pre-Heartstone death.
	UPROPERTY(EditDefaultsOnly, Category = "Soul Constellation | Imprint Buffer")
	float DecayOnDeathFraction = 0.2f;

	// Each imprint's weight is scaled by this before adding to IntegrationDebt.
	// Allows per-designer tuning without touching code.
	UPROPERTY(EditDefaultsOnly, Category = "Soul Constellation | Imprint Buffer")
	float DebtWeightScale = 0.08f;

	// Maximum imprint entries before old records are evicted (FIFO).
	UPROPERTY(EditDefaultsOnly, Category = "Soul Constellation | Imprint Buffer")
	int32 MaxImprintCapacity = 64;

	// Cached previous stage so we only broadcast on actual transitions.
	EIntegrationDebtStage CachedDebtStage = EIntegrationDebtStage::Dormant;

	void EvaluateAndBroadcastStageChange();
};
