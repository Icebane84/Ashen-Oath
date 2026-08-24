// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightAudioSubsystem.generated.h"

/**
 * UAshenShroudKnightAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing high-frequency paranoia ringing (3500Hz), phase-shifting wooshes, and sibilant whispers.
 */
UCLASS()
class ASHENOATH_API UAshenShroudKnightAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenShroudKnightAudioSubsystem();

	/** Evaluates paranoia high-frequency ringing gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Boss")
	float EvaluateParanoiaRingingGain(float Infection01) const;

	/** Evaluates phase-shift whoosh volume [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Boss")
	float EvaluatePhaseWhooshVolume(EShroudKnightPhaseState PhaseState) const;
};
