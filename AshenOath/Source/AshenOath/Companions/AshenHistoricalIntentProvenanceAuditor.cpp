// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenHistoricalIntentProvenanceAuditor.h"

UAshenHistoricalIntentProvenanceAuditor::UAshenHistoricalIntentProvenanceAuditor()
{
}

EIntentConfidenceTier UAshenHistoricalIntentProvenanceAuditor::AuditIntentConfidence(
	bool bTargetIsInnocent,
	const FCanonicalSoulStateVector& SoulState) const
{
	// Invariant: High Grace/Defiance + Low Dysregulation -> High Confidence
	if (bTargetIsInnocent)
	{
		if (SoulState.AccumulatedDysregulation < 0.40f && (SoulState.DominantLens == EOntologicalLens::Grace || SoulState.DominantLens == EOntologicalLens::Defiance))
		{
			return EIntentConfidenceTier::Confident;
		}
		if (SoulState.AccumulatedDysregulation < 0.20f)
		{
			return EIntentConfidenceTier::Absolute;
		}
	}

	if (SoulState.AccumulatedDysregulation >= 0.70f)
	{
		return EIntentConfidenceTier::Doubtful;
	}

	return EIntentConfidenceTier::Tentative;
}
