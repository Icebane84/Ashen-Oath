// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenConvergenceAudioSubsystem.generated.h"

/**
 * UAshenConvergenceAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing demonic Eldrin whisper panning, Stem 02 dissonance modulation, and flow state chordal blooms.
 */
UCLASS()
class ASHENOATH_API UAshenConvergenceAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenConvergenceAudioSubsystem();

	/** Evaluates 3D spatial whisper panning angle [degrees] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Audio")
	float EvaluateWhisperSpatialPanAngle(float Sanity) const;

	/** Evaluates White Flame resonance stem 06 gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Audio")
	float EvaluateWhiteFlameStemGain(bool bFlowStateActive) const;
};
