// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSeparationVelocityCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSeparationVelocityCalculatedSignature, float, SeparationVelocity, float, RelationalDivergenceRate);

/**
 * UAshenSeparationVelocityCalculator
 *
 * Subsystem calculating Separation Velocity (the rate at which unresolved trauma deepens relational/identity divergence).
 */
UCLASS()
class ASHENOATH_API UAshenSeparationVelocityCalculator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SeparationVelocity")
	float CalculateSeparationVelocity(float IntegrationDebt, float UnresolvedTraumaCount);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SeparationVelocity|Events")
	FOnSeparationVelocityCalculatedSignature OnVelocityCalculated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SeparationVelocity")
	float ActiveSeparationVelocity = 0.0f;
};
