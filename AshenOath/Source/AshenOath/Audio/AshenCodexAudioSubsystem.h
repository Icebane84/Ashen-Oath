// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenCodexAudioSubsystem.generated.h"

/**
 * UAshenCodexAudioSubsystem
 * 
 * Synthesizes parchment page flips, runic chime hums, and ancient whisper ambiences.
 */
UCLASS()
class ASHENOATH_API UAshenCodexAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCodexAudioSubsystem();

	/** Evaluates the fundamental resonant frequency (Hz) for a relic tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Archive")
	float EvaluateRelicHumPitchHz(ERelicRarityTier Rarity) const;
};
