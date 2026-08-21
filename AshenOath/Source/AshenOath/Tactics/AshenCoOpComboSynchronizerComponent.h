// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenCoOpComboSynchronizerComponent.generated.h"

/**
 * UAshenCoOpComboSynchronizerComponent
 * 
 * Tracks player kinetic cleave timing against queued companion actions,
 * evaluating multi-character synchronized burst damage.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCoOpComboSynchronizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCoOpComboSynchronizerComponent();

	/** Evaluates combo execution state based on participant count and timing delta */
	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics")
	FTemporalComboExecutionState EvaluateComboSync(
		int32 ParticipantCount,
		float TimingDeltaSeconds,
		float MaxWindowSeconds) const;
};
