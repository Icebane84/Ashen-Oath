// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSymbioticPeakResonanceSilenceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPeakResonanceSilenceTriggeredSignature, bool, bIsPeakResonanceActive, float, LethalSilenceMultiplier);

/**
 * UAshenSymbioticPeakResonanceSilenceComponent
 *
 * Component enforcing pure lethal silence & dual-execution synchronization during peak companion resonance (Directive #1).
 * Disables combat barks/tactical shouts and dynamically unifies MetaSounds music rhythm.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSymbioticPeakResonanceSilenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSymbioticPeakResonanceSilenceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PeakResonance")
	void EvaluateResonanceSilence(float ActiveTrustScore, float ProximityDistance);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PeakResonance|Events")
	FOnPeakResonanceSilenceTriggeredSignature OnResonanceSilenceTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PeakResonance")
	bool bIsPeakResonanceActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PeakResonance")
	float CalculatedLethalSilenceMultiplier = 1.0f;
};
