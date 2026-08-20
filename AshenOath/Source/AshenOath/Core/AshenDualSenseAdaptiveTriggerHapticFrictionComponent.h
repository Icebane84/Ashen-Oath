// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualSenseAdaptiveTriggerHapticFrictionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAdaptiveTriggerResistanceAppliedSignature, float, TriggerResistanceThreshold, bool, bIsThresholdBroken);

/**
 * UAshenDualSenseAdaptiveTriggerHapticFrictionComponent
 *
 * Component locking adaptive triggers with physical resistance thresholds & asymmetric haptic thrums (PRS-001-UI-006).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseAdaptiveTriggerHapticFrictionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualSenseAdaptiveTriggerHapticFrictionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AdaptiveTriggers")
	bool EvaluateTriggerPressPastThreshold(float AppliedForceNormalized);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AdaptiveTriggers|Events")
	FOnAdaptiveTriggerResistanceAppliedSignature OnTriggerResistanceUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AdaptiveTriggers")
	float ResistanceThreshold = 0.85f;
};
