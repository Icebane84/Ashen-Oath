// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenMemoryProvenanceAuditor.generated.h"

/**
 * UAshenMemoryProvenanceAuditor
 * 
 * Audits cited memories to ensure zero narrative hallucination:
 * - Checks active imprint buffers
 * - Validates causal lineage tags
 */
UCLASS()
class ASHENOATH_API UAshenMemoryProvenanceAuditor : public UObject
{
	GENERATED_BODY()

public:
	UAshenMemoryProvenanceAuditor();

	/** Audits memory citation against active memory buffer */
	UFUNCTION(BlueprintPure, Category = "Ashen|Soul|Provenance")
	bool AuditMemoryProvenance(
		const FString& CitedMemoryId,
		const TArray<FString>& AuthorizedImprints) const;
};
