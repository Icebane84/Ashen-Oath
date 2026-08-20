// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenInterpretiveClaritySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInterpretiveClarityEvaluatedSignature, float, CurrentClarityScore, bool, bResistedWhisper);

/**
 * UAshenInterpretiveClaritySubsystem
 *
 * Subsystem evaluating Kaelen's Interpretive Clarity (Discernment) against entropic narrative whispers.
 */
UCLASS()
class ASHENOATH_API UAshenInterpretiveClaritySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Clarity")
	bool EvaluateClarityAgainstWhisper(float WhisperErosionIntensity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Clarity|Events")
	FOnInterpretiveClarityEvaluatedSignature OnClarityEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Clarity")
	float ActiveClarityScore = 0.85f;
};
