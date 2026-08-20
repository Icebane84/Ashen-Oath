// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSalienceGateTriggerEvaluatorComponent.generated.h"

/**
 * UAshenSalienceGateTriggerEvaluatorComponent
 * 
 * Evaluates discrete conditions to trigger slow-loop inner voice compilation:
 * - Debt Stage Transitions (0.50, 0.75, 1.0)
 * - Relational Ruptures (Delta >= 0.15)
 * - Lens Shifts
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSalienceGateTriggerEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSalienceGateTriggerEvaluatorComponent();

	/** Checks whether a soul state change justifies a salience trigger */
	UFUNCTION(BlueprintPure, Category = "Ashen|Soul|Salience")
	bool EvaluateSalienceTrigger(
		const FCanonicalSoulStateVector& OldState,
		const FCanonicalSoulStateVector& NewState,
		ESalienceTriggerClass& OutTriggerClass) const;
};
