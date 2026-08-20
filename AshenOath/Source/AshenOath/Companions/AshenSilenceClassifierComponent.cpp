// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenSilenceClassifierComponent.h"

UAshenSilenceClassifierComponent::UAshenSilenceClassifierComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FSilenceEvaluationSnapshot UAshenSilenceClassifierComponent::ClassifySilence(
	float SilenceDuration,
	float CombatRecencySeconds,
	float AccumulatedDysregulation,
	bool bActiveMemoryTrigger) const
{
	FSilenceEvaluationSnapshot Snapshot;
	Snapshot.EvaluationId = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphensLower);
	Snapshot.SilenceDurationSeconds = SilenceDuration;

	if (bActiveMemoryTrigger || AccumulatedDysregulation >= 0.70f)
	{
		Snapshot.Classification = ESomaticSilenceClassification::DestabilizingCrisis;
		Snapshot.CompanionConfidence = 0.90f;
		Snapshot.RecommendedSpacingUU = 200.0f; // Close in to ground / take point
		return Snapshot;
	}

	if (CombatRecencySeconds <= 15.0f && AccumulatedDysregulation >= 0.35f)
	{
		Snapshot.Classification = ESomaticSilenceClassification::TraumaticAftermath;
		Snapshot.CompanionConfidence = 0.80f;
		Snapshot.RecommendedSpacingUU = 250.0f; // Match step / supportive presence
		return Snapshot;
	}

	Snapshot.Classification = ESomaticSilenceClassification::Contemplative;
	Snapshot.CompanionConfidence = 0.75f;
	Snapshot.RecommendedSpacingUU = 500.0f; // Respectful exploratory spacing
	return Snapshot;
}
