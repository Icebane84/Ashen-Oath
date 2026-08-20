// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenMarginaliaProvenanceValidator.generated.h"

/**
 * UAshenMarginaliaProvenanceValidator
 * 
 * Validates marginalia entries against active memory buffers and tag registries.
 */
UCLASS()
class ASHENOATH_API UAshenMarginaliaProvenanceValidator : public UObject
{
	GENERATED_BODY()

public:
	UAshenMarginaliaProvenanceValidator();

	/** Audits marginalia entries to discard unearned citations */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Provenance")
	bool ValidateEntries(
		const TArray<FMarginaliaEntry>& InEntries,
		const TArray<FString>& AuthorizedImprints,
		TArray<FMarginaliaEntry>& OutValidatedEntries) const;
};
