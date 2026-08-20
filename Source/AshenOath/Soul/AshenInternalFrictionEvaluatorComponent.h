// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenInternalFrictionEvaluatorComponent.generated.h"

/**
 * UAshenInternalFrictionEvaluatorComponent
 * 
 * Computes Kaelen's independent Internal Friction scalar (Phi_internal in [0.0, 1.0]).
 * Evaluates Integration Debt, Accumulated Dysregulation, Lens Shift, Threat Intensity, and Resolve.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInternalFrictionEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInternalFrictionEvaluatorComponent();

	/** Computes pure internal friction scalar according to CONTRACT-SPEC-051 */
	UFUNCTION(BlueprintPure, Category = "Ashen|Soul")
	float EvaluateInternalFriction(
		const FCanonicalSoulStateVector& SoulState,
		float ThreatIntensity) const;

	/** Evaluates continuous dysregulation stage classification */
	UFUNCTION(BlueprintPure, Category = "Ashen|Soul")
	int32 GetCurrentDysregulationStage(const FCanonicalSoulStateVector& SoulState) const;

	/** Evaluates whether high friction enables violent desperation modifiers */
	UFUNCTION(BlueprintPure, Category = "Ashen|Soul")
	bool IsInSupportedStruggleBand(float InternalFriction, float RelationalFlow) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	float SupportedStruggleFrictionThreshold = 0.80f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Soul")
	float SupportedStruggleFlowThreshold = 0.75f;
};
