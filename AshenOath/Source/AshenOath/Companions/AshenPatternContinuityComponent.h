// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenPatternContinuityComponent.generated.h"

/**
 * UAshenPatternContinuityComponent
 * 
 * Actor Component analyzing the historical memory graph nodes to evaluate
 * rupture and repair patterns over time without string-parsing or hardcoded scripts.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPatternContinuityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPatternContinuityComponent();

	/** Evaluates recent memory graph nodes to calculate companion repair matrix */
	UFUNCTION(BlueprintPure, Category = "Ashen|Ecology")
	FAshenRepairMatrix EvaluateRepairHistory(
		const FGuid& CompanionId,
		const TArray<FMemoryImprintPayload>& MemoryGraph) const;

	/** Determines whether companion will execute costly presence based on faith threshold */
	UFUNCTION(BlueprintPure, Category = "Ashen|Ecology")
	bool ShouldExecuteCostlyPresence(
		float CompanionTrust,
		float CurrentThreat,
		const FAshenRepairMatrix& RepairHistory) const;

	/** Calculates synarchy ratio from sync finishers vs total relevant events */
	UFUNCTION(BlueprintPure, Category = "Ashen|Ecology")
	float CalculateSynarchyRatio(int32 SyncCount, int32 TotalEvents) const;
};
