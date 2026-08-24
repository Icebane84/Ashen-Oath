// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaSomaticsHapticBridge.generated.h"

/**
 * UAshenTraumaSomaticsHapticBridge
 * 
 * Synchronizes DualSense controller haptic heart palpitations directly to real-time BPM (60-170 BPM) and blade slag resistance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaSomaticsHapticBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaSomaticsHapticBridge();

	/** Evaluates DualSense haptic pulse frequency and trigger resistance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics|Haptics")
	void EvaluateSomaticHaptics(
		float HeartRateBPM,
		float BladeSootScalar,
		float& OutHeartPulseIntervalSeconds,
		float& OutRightTriggerSlagResistance) const;
};
