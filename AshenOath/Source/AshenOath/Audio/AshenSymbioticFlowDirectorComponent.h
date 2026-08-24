// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenSymbioticFlowDirectorComponent.generated.h"

/**
 * UAshenSymbioticFlowDirectorComponent
 * 
 * Coordinates the 8-second Symbiotic Resonance flow window, doubling party stamina regeneration and activating vocal overrides.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSymbioticFlowDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSymbioticFlowDirectorComponent();

	/** Evaluates party stamina recovery multiplier [1.0x to 2.0x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Flow")
	float EvaluateStaminaRegenMultiplier(ECombatFlowState FlowState) const;

	/** Evaluates combo burst damage bonus [0% to 30%] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Flow")
	float EvaluateFlowDamageBonus(ECombatFlowState FlowState) const;

	/** Gets canonical flow state duration */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Flow")
	float GetFlowStateDurationSeconds() const { return 8.0f; }
};
