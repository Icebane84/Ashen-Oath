// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenBioAcousticHeartbeatEvaluator.generated.h"

/**
 * UAshenBioAcousticHeartbeatEvaluator
 * 
 * Computes real-time dynamic heart rate BPM (60 to 170 BPM) and respiration pacing.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBioAcousticHeartbeatEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBioAcousticHeartbeatEvaluator();

	/** Computes dynamic heart rate BPM based on combat state and vein corruption */
	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics|Audio")
	float EvaluateHeartRateBPM(bool bInCombat, float VeinCorruption) const;
};
