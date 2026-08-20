// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenRelationalFlowEvaluatorComponent.generated.h"

/**
 * UAshenRelationalFlowEvaluatorComponent
 * 
 * Computes the independent Relational Flow scalar (Psi_relational in [0.0, 1.0]).
 * Evaluates persistent TrioResonance modulated by physical distance (400.0uu threshold = 0.75f),
 * line-of-sight verification, and active companion support.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalFlowEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalFlowEvaluatorComponent();

	/** Computes situated relational flow scalar according to CONTRACT-SPEC-051 */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions")
	float EvaluateRelationalFlow(
		float TrioResonance,
		float ImmediateThreat,
		float CompanionProximityFactor,
		bool bCompanionSupportPresent) const;

	/** Converts world distance in Unreal Units to CompanionProximityFactor */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions")
	float CalculateProximityFactorFromDistance(float DistanceUU) const;

	/** Evaluates whether companion support is active from proximity factor and LOS */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions")
	bool EvaluateCompanionSupportPresent(float ProximityFactor, bool bLineOfSight) const;

	/** Canonical support threshold: 0.75f corresponds to distance <= 400.0uu */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Companions")
	float CanonicalSupportProximityThreshold = 0.75f;
};
