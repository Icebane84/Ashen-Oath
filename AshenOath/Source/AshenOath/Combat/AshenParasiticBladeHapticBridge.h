// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticBladeHapticBridge.generated.h"

/**
 * UAshenParasiticBladeHapticBridge
 * 
 * Maps DualSense adaptive trigger resistance based on blade mass (45-220kg), parasitic heartbeat pulses, and Gloomwood needle snap.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParasiticBladeHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParasiticBladeHapticBridge();

	/** Evaluates DualSense trigger resistance and motor rumble for parasitic blade */
	UFUNCTION(BlueprintPure, Category = "Ashen|Blade|Haptics")
	void EvaluateBladeHaptics(
		float BladeMassKg,
		float Corruption01,
		bool bGloomwoodFrozen,
		float& OutTriggerMassResistance,
		float& OutParasiticHeartbeatPulse,
		float& OutGloomwoodFreezeRumble);
};
