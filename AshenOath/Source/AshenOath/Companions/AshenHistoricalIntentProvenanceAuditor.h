// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenHistoricalIntentProvenanceAuditor.generated.h"

/**
 * UAshenHistoricalIntentProvenanceAuditor
 * 
 * Computes intent confidence tiers based on historical choices and active lens.
 */
UCLASS()
class ASHENOATH_API UAshenHistoricalIntentProvenanceAuditor : public UObject
{
	GENERATED_BODY()

public:
	UAshenHistoricalIntentProvenanceAuditor();

	/** Audits historical patterns to calculate intent confidence */
	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Intent")
	EIntentConfidenceTier AuditIntentConfidence(
		bool bTargetIsInnocent,
		const FCanonicalSoulStateVector& SoulState) const;
};
