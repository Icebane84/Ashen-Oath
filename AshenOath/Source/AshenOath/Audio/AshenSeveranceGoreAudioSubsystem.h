// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenSeveranceTypes.h"
#include "AshenSeveranceGoreAudioSubsystem.generated.h"

/**
 * UAshenSeveranceGoreAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers: 180Hz heavy bone-cleaving sub-bass impacts and 3.2kHz wet arterial blood splatters.
 */
UCLASS()
class ASHENOATH_API UAshenSeveranceGoreAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSeveranceGoreAudioSubsystem();

	/** Evaluates acoustic gains for severance impact */
	UFUNCTION(BlueprintPure, Category = "Ashen|Severance|Audio")
	void EvaluateSeveranceAcoustics(
		ESeveranceSeverityTier Severity,
		float& OutBoneCrushGain,
		float& OutBloodSplatterGain) const;
};
