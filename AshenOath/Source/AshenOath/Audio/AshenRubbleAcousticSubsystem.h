// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubbleAcousticSubsystem.generated.h"

/**
 * UAshenRubbleAcousticSubsystem
 * 
 * MetaSounds audio subsystem synthesizing low-frequency structural stress groans (40-120Hz), high-frequency rock fractures, and impact dust whooshes.
 */
UCLASS()
class ASHENOATH_API UAshenRubbleAcousticSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRubbleAcousticSubsystem();

	/** Evaluates structural groan gain [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Rubble")
	float EvaluateStructuralGroanGain(float StructuralIntegrity01) const;

	/** Evaluates fracture crack frequency in Hz [1200Hz to 4800Hz] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Rubble")
	float EvaluateFractureFrequencyHz(ERubbleFractureTier Tier) const;
};
