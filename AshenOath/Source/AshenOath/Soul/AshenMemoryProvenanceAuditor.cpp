// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenMemoryProvenanceAuditor.h"

UAshenMemoryProvenanceAuditor::UAshenMemoryProvenanceAuditor()
{
}

bool UAshenMemoryProvenanceAuditor::AuditMemoryProvenance(
	const FString& CitedMemoryId,
	const TArray<FString>& AuthorizedImprints) const
{
	if (CitedMemoryId.IsEmpty())
	{
		return true; // No citation to audit
	}

	return AuthorizedImprints.Contains(CitedMemoryId);
}
