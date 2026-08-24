// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenSootProvenanceLedgerEvaluator.generated.h"

/**
 * UAshenSootProvenanceLedgerEvaluator
 * 
 * Computes cumulative soot layer microns, kinetic slag accumulation, and burnishing restoration percentages.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSootProvenanceLedgerEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSootProvenanceLedgerEvaluator();

	/** Calculates cumulative campaign soot across all 10 scenarios [microns] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Soot")
	float CalculateTotalCampaignSoot(const TArray<float>& ScenarioSootMicrons) const;

	/** Evaluates weapon luster after campfire burnishing [0.0 to 1.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Soot")
	float EvaluateWeaponLuster(float CurrentSootMicrons, float MaxSootMicrons) const;
};
