// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenBladeAscensionEvaluator.generated.h"

/**
 * UAshenBladeAscensionEvaluator
 * 
 * Computes whether Oathbringer meets the narrative and sanctum boss milestones required to ascend to the next metallurgical tier.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeAscensionEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeAscensionEvaluator();

	/** Evaluates if eligible to ascend from current tier to target tier */
	UFUNCTION(BlueprintPure, Category = "Ashen|RunicForge|Evaluator")
	bool IsEligibleForAscension(
		EOathbringerAscensionTier CurrentTier,
		int32 DefeatedSanctumBosses,
		int32 IgnitedHearthstones,
		int32 SolvedForensicCases) const;
};
