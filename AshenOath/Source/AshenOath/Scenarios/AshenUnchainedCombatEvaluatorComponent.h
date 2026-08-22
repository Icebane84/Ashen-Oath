// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenUnchainedCombatEvaluatorComponent.generated.h"

/**
 * UAshenUnchainedCombatEvaluatorComponent
 * 
 * Computes damage scalars, kinetic lunge speed bonuses, and cooldown exhaustion states for Unchained Mode.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnchainedCombatEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnchainedCombatEvaluatorComponent();

	/** Evaluates damage multiplier based on active Unchained phase */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	float EvaluateDamageMultiplier(EUnchainedVesselPhase Phase) const;

	/** Evaluates lunge speed multiplier */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario5")
	float EvaluateLungeVelocityMultiplier(EUnchainedVesselPhase Phase) const;
};
