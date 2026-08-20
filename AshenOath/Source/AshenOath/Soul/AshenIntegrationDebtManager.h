// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenIntegrationDebtManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDebtStageEscalated, EAshenIntegrationDebtStage, OldStage, EAshenIntegrationDebtStage, NewStage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnForcedCollapseThresholdReached, float, CurrentDebt);

/**
 * UAshenIntegrationDebtManager
 * World Subsystem evaluating real-time integration debt escalation across the 4 canonical stages.
 * Broadcasts escalation deltas to audio, UI, combat, and world transition systems.
 */
UCLASS()
class ASHENOATH_API UAshenIntegrationDebtManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Integration Debt")
	FOnDebtStageEscalated OnDebtStageEscalated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Integration Debt")
	FOnForcedCollapseThresholdReached OnForcedCollapseThresholdReached;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Integration Debt")
	float CurrentIntegrationDebt = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Integration Debt")
	EAshenIntegrationDebtStage CurrentDebtStage = EAshenIntegrationDebtStage::Stable;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Integration Debt")
	void UpdateIntegrationDebt(float DebtDelta);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Integration Debt")
	EAshenIntegrationDebtStage EvaluateDebtStage(float DebtValue) const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Integration Debt")
	float GetParryWindowMultiplier() const;
};
