// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSymmetricHapticPulseCalculator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAsymmetricHapticsCalculatedSignature, float, LeftCorruptionThrumFrequency, float, RightPanicPulseFrequency);

/**
 * UAshenSymmetricHapticPulseCalculator
 *
 * Calculator computing asymmetric left (corruption thrum) vs right (Kaelen panic) haptic frequencies (PRS-001-UI-006).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSymmetricHapticPulseCalculator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|AsymmetricHaptics")
	void CalculateAsymmetricHapticPulses(float CorruptionLevel, float PanicBPM);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AsymmetricHaptics|Events")
	FOnAsymmetricHapticsCalculatedSignature OnHapticsCalculated;
};
