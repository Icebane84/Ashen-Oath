// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenSoulTypes.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenSigilResonanceEvaluator.generated.h"

class UAshenRunicForgeBalanceDataAsset;

/**
 * UAshenSigilResonanceEvaluator
 * Evaluates 0.15s Flow Glint hybrid finisher triggers strictly against spatial distance (<=200uu) and Relational Flow.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSigilResonanceEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen|SigilResonance")
	bool EvaluateHybridFinisher(
		EGuardSigilSocket StanceA,
		EGuardSigilSocket StanceB,
		const FSomaticState& SomaticState,
		float CompanionDistance,
		const UAshenRunicForgeBalanceDataAsset* BalanceData,
		FHybridFinisherPayload& OutPayload) const;

	/** Legacy/Direct evaluator checking if two sigils can trigger dual resonance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|SigilResonance")
	bool CanTriggerResonance(ESigilResonanceEffect SigilA, ESigilResonanceEffect SigilB) const;

	/** Evaluates damage multiplier from dual sigil combinations */
	UFUNCTION(BlueprintCallable, Category = "Ashen|SigilResonance")
	float EvaluateHybridFinisherDamage(ESigilResonanceEffect SigilA, ESigilResonanceEffect SigilB) const;
};
