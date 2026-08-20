// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenMarginaliaProvenanceValidator.h"

UAshenMarginaliaProvenanceValidator::UAshenMarginaliaProvenanceValidator()
{
}

bool UAshenMarginaliaProvenanceValidator::ValidateEntries(
	const TArray<FMarginaliaEntry>& InEntries,
	const TArray<FString>& AuthorizedImprints,
	TArray<FMarginaliaEntry>& OutValidatedEntries) const
{
	OutValidatedEntries.Empty();

	for (const FMarginaliaEntry& Entry : InEntries)
	{
		if (Entry.InscriptionText.IsEmpty())
		{
			continue;
		}

		// Provenance check
		if (!Entry.TargetMemoryId.IsEmpty() && AuthorizedImprints.Num() > 0)
		{
			if (!AuthorizedImprints.Contains(Entry.TargetMemoryId))
			{
				continue; // Skip unearned citation
			}
		}

		OutValidatedEntries.Add(Entry);
	}

	return OutValidatedEntries.Num() > 0;
}
