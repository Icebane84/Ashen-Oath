// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenCSEAudioSubsystem.generated.h"

/**
 * UAshenCSEAudioSubsystem
 * 
 * Synthesizes dynamic audio cues for party psychological consensus (432Hz pure chimes) vs cognitive dissonance (110Hz detuned string scrapes).
 */
UCLASS()
class ASHENOATH_API UAshenCSEAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenCSEAudioSubsystem();

	/** Evaluates acoustic parameters for current dissonance level */
	UFUNCTION(BlueprintPure, Category = "Ashen|CSE|Audio")
	void EvaluateCSEAcoustics(float DissonanceIndex, float& OutHarmonyChimeGain, float& OutDissonantScrapeGain, float& OutDetuneHz) const;
};
