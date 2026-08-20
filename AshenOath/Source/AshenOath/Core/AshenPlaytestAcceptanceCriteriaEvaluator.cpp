// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 812: Ashen Playtest Acceptance Criteria Evaluator

#include "AshenPlaytestAcceptanceCriteriaEvaluator.h"

void UAshenPlaytestAcceptanceCriteriaEvaluator::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalCriteriaVerified = 5;
	UE_LOG(LogTemp, Log, TEXT("UAshenPlaytestAcceptanceCriteriaEvaluator: Initialized — Playtest Acceptance Criteria Evaluator ONLINE."));
}

bool UAshenPlaytestAcceptanceCriteriaEvaluator::EvaluatePlaytestCriteria(FName ObservationCategory, float PhysicalTensionRating)
{
	const bool bMet = (PhysicalTensionRating >= 7.0f);
	OnCriteriaEvaluated.Broadcast(ObservationCategory, bMet);

	UE_LOG(LogTemp, Warning, TEXT("UAshenPlaytestAcceptanceCriteriaEvaluator: PLAYTEST CRITERIA EVALUATED -> Category: '%s' | Tension Rating: %.1f/10 | Target Met: %s."),
		*ObservationCategory.ToString(), PhysicalTensionRating, bMet ? TEXT("TRUE (Emotional Target Achieved)") : TEXT("FALSE"));

	return bMet;
}
