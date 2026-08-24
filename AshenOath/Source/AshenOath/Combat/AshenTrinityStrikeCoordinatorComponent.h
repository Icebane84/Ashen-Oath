// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenTrinityStrikeCoordinatorComponent.generated.h"

/**
 * UAshenTrinityStrikeCoordinatorComponent
 * 
 * Tracks the 3-step Trinity Strike combo execution window (6.0s timeout), combo damage scaling, and boss poise vulnerability.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrinityStrikeCoordinatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTrinityStrikeCoordinatorComponent();

	/** Evaluates combo burst damage multiplier [1.0x to 3.5x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Trinity")
	float EvaluateTrinityDamageMultiplier(ETrinityStrikeStep Step) const;

	/** Gets the combo window timeout in seconds */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Trinity")
	float GetComboTimeoutSeconds() const { return 6.0f; }

	/** Validates if next step in sequence is valid */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Trinity")
	bool IsStepValid(ETrinityStrikeStep CurrentStep, ETrinityStrikeStep AttemptedStep) const;
};
