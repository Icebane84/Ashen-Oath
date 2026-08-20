// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMacroSystemicContractTypes.h"
#include "AshenUniversalSomaticEngineSubsystem.generated.h"

/**
 * UAshenUniversalSomaticEngineSubsystem
 * 
 * Central translation authority deriving situated somatic states (Phi_internal, Psi_relational,
 * ParasitePressure, WillCapacity, IsolationPressure) and action-congruence resistance.
 * Evaluates the Salience Gate, calculates psychosomatic stamina drag and relational buffering.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenUniversalSomaticEngineSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenUniversalSomaticEngineSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Evaluates continuous somatic state from soul, relational, and contextual inputs */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Somatic")
	FSomaticState EvaluateSomaticState(
		const FCanonicalSoulStateVector& SoulState,
		const FCanonicalRelationalMatrix& RelationalState,
		const FContextualPressureState& ContextPressure,
		FGuid TransactionId,
		int64 StateVersion);

	/** Evaluates specific action congruence resistance for Trial of Will execution */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Somatic")
	FActionCongruenceResult EvaluateActionCongruence(
		const FCanonicalSoulStateVector& SoulState,
		const FCanonicalRelationalMatrix& RelationalState,
		FGameplayTag IntendedActionTag,
		EOntologicalLens IntendedLens,
		float MemorySeverity,
		FName TargetCompanionName,
		FGuid TransactionId,
		int64 StateVersion);

	/** Evaluates the Salience Gate to determine whether expression intent should dispatch */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Somatic")
	bool EvaluateSalienceGate(const FSomaticState& CurrentState, double CurrentTimeSeconds, FSomaticExpressionIntent& OutIntent);

	/** Calculates effective stamina regen scalar based on psychosomatic cross-coupling */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatic")
	float CalculateEffectiveStaminaRegenScalar(float InternalFriction, float BaseRegenScalar = 1.0f) const;

	/** Calculates net somatic exhaustion penalty with relational buffering */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatic")
	float CalculateNetSomaticExhaustionPenalty(float InternalFriction, float RelationalFlow) const;

	/** Broadcast delegate when new somatic state is derived */
	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatic")
	FOnSomaticStateUpdated OnSomaticStateUpdated;

	/** Broadcast delegate when action congruence is evaluated */
	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatic")
	FOnActionCongruenceEvaluated OnActionCongruenceEvaluated;

	/** Broadcast delegate when expression intent passes the Salience Gate */
	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatic")
	FOnExpressionIntentDispatched OnExpressionIntentDispatched;

	UFUNCTION(BlueprintPure, Category = "Ashen|Somatic")
	const FSomaticState& GetLatestSomaticState() const { return CachedSomaticState; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Somatic")
	const FSomaticExpressionIntent& GetLatestExpressionIntent() const { return CachedExpressionIntent; }

private:
	UPROPERTY()
	FSomaticState CachedSomaticState;

	UPROPERTY()
	FSomaticExpressionIntent CachedExpressionIntent;

	UPROPERTY()
	FSalienceBudget SalienceBudget;
};
