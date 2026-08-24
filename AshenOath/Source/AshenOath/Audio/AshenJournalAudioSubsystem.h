// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenJournalAudioSubsystem.generated.h"

/**
 * UAshenJournalAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing parchment turning, quill scribing scratches (400Hz), and campfire crackling embers (80Hz-2400Hz).
 */
UCLASS()
class ASHENOATH_API UAshenJournalAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenJournalAudioSubsystem();

	/** Evaluates quill scribing acoustic gain based on writing speed [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Journal")
	float EvaluateQuillScribingGain(float WritingSpeed01) const;

	/** Evaluates campfire hearth crackle intensity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Journal")
	float EvaluateCampfireCrackleGain(ECampfireReflectionMood Mood) const;
};
