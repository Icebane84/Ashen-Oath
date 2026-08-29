// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalAudioSubsystem.generated.h"

/**
 * UAshenSanctuarySurvivalAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers for howling blizzard muffling (-12dB in caverns), crackling hearthstone fires, and soothing sanctuary peace harmonies.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuarySurvivalAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSanctuarySurvivalAudioSubsystem();

	/** Evaluates acoustic parameters for active shelter tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Survival|Audio")
	void EvaluateShelterAcoustics(
		EThermalShelterTier Tier,
		float& OutWindHowlLowPassHz,
		float& OutCracklingFireGain,
		float& OutSanctuaryPeaceHarmonyGain) const;
};
