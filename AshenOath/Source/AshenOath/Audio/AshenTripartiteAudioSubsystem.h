// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteAudioSubsystem.generated.h"

/**
 * UAshenTripartiteAudioSubsystem
 * 
 * MetaSounds audio subsystem synthesizing harmonic Solfeggio triad resonance chords (396Hz, 528Hz, 639Hz).
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTripartiteAudioSubsystem();

	/** Returns the primary harmonic Solfeggio frequency for the active tripartite mode */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Tripartite")
	float EvaluateTripartiteResonanceFrequency(ETripartiteBehaviorMode Mode) const;
};
