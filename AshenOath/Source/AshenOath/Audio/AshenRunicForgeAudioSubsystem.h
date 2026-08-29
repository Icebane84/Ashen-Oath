// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenRunicForgeAudioSubsystem.generated.h"

/**
 * UAshenRunicForgeAudioSubsystem
 * 
 * Synthesizes dynamic MetaSounds acoustic layers: 850Hz ringing heavy hammer anvil clangs, quench oil sizzles, and deep harmonic fuller seam humming.
 */
UCLASS()
class ASHENOATH_API UAshenRunicForgeAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRunicForgeAudioSubsystem();

	/** Evaluates forge acoustic parameters */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|Audio")
	void EvaluateForgeAcoustics(
		EOathbringerAscensionTier Tier,
		bool bStrikingAnvil,
		float& OutAnvilClangGain,
		float& OutRunicSeamHumGain) const;
};
