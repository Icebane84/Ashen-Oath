// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenBossTensionAudioSubsystem.generated.h"

/**
 * UAshenBossTensionAudioSubsystem
 * 
 * Modulates boss battle orchestral tension, distortion, and tempo across Phases 1-3.
 */
UCLASS()
class ASHENOATH_API UAshenBossTensionAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenBossTensionAudioSubsystem();

	/** Evaluates music tension scalar based on active phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Boss")
	float EvaluateMusicTension(EBossEncounterPhase Phase) const;
};
