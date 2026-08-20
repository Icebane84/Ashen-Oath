// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSomaticIntrusionPanicEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSomaticPanicEvaluatedSignature, float, TunnelVisionScale, float, PulseRateBPM);

/**
 * UAshenSomaticIntrusionPanicEvaluator
 *
 * Subsystem evaluating physiological panic parameters (tunnel vision, spatial distortion, pulse rate) (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenSomaticIntrusionPanicEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SomaticPanic")
	void EvaluateSomaticPanic(float HealthPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SomaticPanic|Events")
	FOnSomaticPanicEvaluatedSignature OnPanicEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SomaticPanic")
	float ActivePulseRateBPM = 70.0f;
};
