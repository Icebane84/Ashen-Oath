// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenAdaptiveTriggerArbitratorComponent.generated.h"

/**
 * UAshenAdaptiveTriggerArbitratorComponent
 * 
 * Arbitrates between competing gameplay demands for adaptive trigger haptics,
 * enforcing strict Priority 1 (Dialogue Lockout) > Priority 2 (Stagger) > Priority 3 (Somatic).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAdaptiveTriggerArbitratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAdaptiveTriggerArbitratorComponent();

	/** Submits a trigger request and returns the winning active configuration */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	FDualSenseTriggerConfig ArbitrateTriggerRequest(
		const FDualSenseTriggerConfig& CurrentConfig,
		const FDualSenseTriggerConfig& IncomingRequest) const;

	/** Evaluates if a request should override the active trigger */
	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	bool ShouldOverride(ETriggerPriorityLevel CurrentPriority, ETriggerPriorityLevel IncomingPriority) const;
};
