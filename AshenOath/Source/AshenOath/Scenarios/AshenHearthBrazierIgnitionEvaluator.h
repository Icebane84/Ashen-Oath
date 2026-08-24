// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenHearthBrazierIgnitionEvaluator.generated.h"

/**
 * UAshenHearthBrazierIgnitionEvaluator
 * 
 * Computes channeling rate and sanctuary safe radius expansion as the ancient Hearth Brazier ignites.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHearthBrazierIgnitionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHearthBrazierIgnitionEvaluator();

	/** Computes safe sanctuary radius in UU based on ignition progress [500uu to 2500uu] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario6|Hearth")
	float EvaluateSanctuaryRadiusUU(float IgnitionProgress) const;
};
