// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCombatKinematicsAudioSubsystem.generated.h"

/**
 * UAshenCombatKinematicsAudioSubsystem
 * 
 * Synthesizes dynamic audio cues for heavy armor movement clanks, cardiac pulse heartbeats, and perfect deflection bell harmonics (880Hz).
 */
UCLASS()
class ASHENOATH_API UAshenCombatKinematicsAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCombatKinematicsAudioSubsystem();

	/** Evaluates armor roll Foley pitch and volume */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Audio")
	void EvaluateArmorRollAudio(EAshenWeightClass WeightClass, float& OutPitch, float& OutVolume) const;

	/** Evaluates parry acoustic pitch [880Hz high resonant chime] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Kinematics|Audio")
	float EvaluateParryChimePitchHz(EParryRiposteQuality Quality) const;
};
