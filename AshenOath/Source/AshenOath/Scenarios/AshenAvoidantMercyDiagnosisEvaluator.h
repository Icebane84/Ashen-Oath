// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenAvoidantMercyDiagnosisEvaluator.generated.h"

/**
 * UAshenAvoidantMercyDiagnosisEvaluator
 * 
 * Enforces the Run D Invariant: Evaluates whether a sparing decision represents Pure Grace vs Dissociated Avoidance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAvoidantMercyDiagnosisEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAvoidantMercyDiagnosisEvaluator();

	/** Diagnoses sparing decision based on internal IntegrationDebt */
	UFUNCTION(BlueprintPure, Category = "Ashen|Waystation")
	EWaystationRunMode DiagnoseSparingAction(float IntegrationDebt) const;
};
