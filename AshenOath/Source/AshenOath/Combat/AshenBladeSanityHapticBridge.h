// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenBladeSanityHapticBridge.generated.h"

/**
 * UAshenBladeSanityHapticBridge
 * 
 * Maps DualSense low-frequency blade heartbeat rumbles (45Hz), high-frequency sanity flutter (180Hz), and flow state resonant purrs.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeSanityHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeSanityHapticBridge();

	/** Evaluates DualSense haptics for convergence dynamics */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Haptics")
	void EvaluateConvergenceHaptics(
		float BladeHunger01,
		float CurrentSanity,
		bool bFlowStateActive,
		float& OutBladeHeartbeatGain,
		float& OutSanityDistortionGain,
		float& OutFlowPurrImpulse);
};
