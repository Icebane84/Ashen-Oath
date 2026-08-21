// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenGarrettTrapGridEvaluatorComponent.generated.h"

/**
 * UAshenGarrettTrapGridEvaluatorComponent
 * 
 * Computes trap coverage efficiency across choke points in the Crimson Clearance vaults.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettTrapGridEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettTrapGridEvaluatorComponent();

	/** Evaluates whether enemy is within detonation radius of any active trap */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario2")
	bool EvaluateTrapTrigger(
		const FVector& EnemyLocation,
		const FVector& TrapLocation,
		float DetonationRadiusCentimeters) const;
};
