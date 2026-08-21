// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenDualSenseHapticResonanceComponent.generated.h"

/**
 * UAshenDualSenseHapticResonanceComponent
 * 
 * Drives 60 BPM (1.0 Hz) rhythmic DualSense haptic pulses and adaptive trigger feedback.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseHapticResonanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualSenseHapticResonanceComponent();

	/** Evaluates haptic resonance profile based on combo phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	FHapticResonanceProfile EvaluateHapticProfile(ETripartiteComboPhase Phase) const;
};
