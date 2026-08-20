// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenOath_ImprintBufferComponent.h"
#include "AshenIntegrationDebtAccumulatorSubsystem.generated.h"

/**
 * UAshenIntegrationDebtAccumulatorSubsystem
 *
 * Fast-moving pressure tracker evaluating volatile integration debt accumulation.
 */
UCLASS()
class ASHENOATH_API UAshenIntegrationDebtAccumulatorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Accumulates integration debt pressure */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Pressure")
	void AccumulateDebt(float DebtDelta);

	/** Returns current integration debt pressure (0.0 - 1.0) */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Pressure")
	float GetIntegrationDebt() const { return CurrentDebt; }

private:
	UPROPERTY()
	float CurrentDebt = 0.0f;
};
