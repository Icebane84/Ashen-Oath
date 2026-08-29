// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "Memory/AshenIntegrationDebtBalanceDataAsset.h"
#include "AshenIntegrationDebtAccumulatorSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIntegrationDebtStageChangedSignature, EAshenIntegrationDebtStage, NewStage, float, CurrentDebt);

/**
 * UAshenIntegrationDebtAccumulatorSubsystem
 *
 * Fast-moving pressure tracker evaluating volatile integration debt accumulation (ENGINE-SPEC-001 Section 2),
 * managing the 5 canonical escalation stages (Stable -> LatentPressure -> MemoryBleed -> RuntimeNoise -> ForcedCollapse),
 * dynamic parry window degradation, and forced Mindscape memory battle triggers.
 */
UCLASS()
class ASHENOATH_API UAshenIntegrationDebtAccumulatorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Accumulates integration debt pressure and evaluates stage escalations */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Pressure")
	void AccumulateDebt(float DebtDelta);

	/** Relieves a portion of integration debt (e.g. 0.15 on memory anchor unseal) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Pressure")
	void RelieveDebt(float DebtRelief);

	/** Completely clears all integration debt (e.g. at Campfires or during White Flame Resolution) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Pressure")
	void ClearAllDebt();

	/** Explicitly sets current integration debt pressure */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Pressure")
	void SetIntegrationDebt(float NewDebt);

	/** Returns current integration debt pressure (0.0 - 1.0) */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Pressure")
	float GetIntegrationDebt() const { return CurrentDebt; }

	/** Returns current escalation stage */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Pressure")
	EAshenIntegrationDebtStage GetCurrentStage() const { return CurrentStage; }

	/** Returns effective parry window in seconds based on current debt degradation */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Pressure")
	float GetEffectiveParryWindow() const;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Pressure|Events")
	FOnIntegrationDebtStageChangedSignature OnIntegrationDebtStageChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Pressure|Balancing")
	UAshenIntegrationDebtBalanceDataAsset* BalanceDataAsset;

private:
	void EvaluateStageTransition();

	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Pressure")
	float CurrentDebt = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Pressure")
	EAshenIntegrationDebtStage CurrentStage = EAshenIntegrationDebtStage::Stable;
};
