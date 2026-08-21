// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicChimeAudioSubsystem.generated.h"

/**
 * UAshenRunicChimeAudioSubsystem
 * 
 * Synthesizes harmonic metallic chimes and anvil resonance tones during forge rituals.
 */
UCLASS()
class ASHENOATH_API UAshenRunicChimeAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRunicChimeAudioSubsystem();

	/** Evaluates the fundamental resonant frequency (Hz) for a socketed tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Reliquary")
	float EvaluateRunicPitchHz(ESoulForgeAttunementTier Tier) const;
};
