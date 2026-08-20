// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenAegisStaggerCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAegisStaggerCalculatedSignature, float, StaggerImpactValue, bool, bInflictsKnockback);

/**
 * UAshenAegisStaggerCalculator
 *
 * Calculator computing kinetic stagger impact inflicted on enemies during Glancing Deflections (PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenAegisStaggerCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AegisStagger")
	float CalculateGlancingStaggerImpact(float EnemyIncomingMass, float DeflectionAngleDegrees);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AegisStagger|Events")
	FOnAegisStaggerCalculatedSignature OnStaggerCalculated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisStagger")
	float LastCalculatedStaggerImpact = 0.0f;
};
