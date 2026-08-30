// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Soul/AshenSoulTypes.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenBladeAscensionEvaluator.generated.h"

class UAshenRunicForgeBalanceDataAsset;

/**
 * UAshenBladeAscensionEvaluator
 * Evaluates Oathbringer's 5-tier blade ascension progression purely from canonical soul state and relational matrix predicates.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenBladeAscensionEvaluator : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Ashen|BladeAscension")
	EOathbringerAscensionTier EvaluateAscensionTier(
		const FSoulStateVector& CanonicalSoul,
		const FRelationalMatrix_V2& RelationalMatrix,
		const UAshenRunicForgeBalanceDataAsset* BalanceData) const;

	/** Legacy/Quest criteria evaluator for Sanctum boss, hearthstone, and forensic progression */
	UFUNCTION(BlueprintCallable, Category = "Ashen|BladeAscension")
	bool IsEligibleForAscension(
		EOathbringerAscensionTier CurrentTier,
		int32 BossKills,
		int32 HearthsLit,
		int32 ForensicCases) const;
};
