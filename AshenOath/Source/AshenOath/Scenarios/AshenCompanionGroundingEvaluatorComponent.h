// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenCompanionGroundingEvaluatorComponent.generated.h"

/**
 * UAshenCompanionGroundingEvaluatorComponent
 * 
 * Evaluates companion skeletal orientation against perceived phantoms to distinguish reality from delusion.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionGroundingEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionGroundingEvaluatorComponent();

	/** Evaluates whether companion skeletal aim vector aligns with threat location */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario4")
	bool EvaluateCompanionGazeAlignment(
		const FVector& CompanionLocation,
		const FVector& CompanionForwardVector,
		const FVector& ThreatLocation,
		float MaxConeAngleDegrees) const;
};
