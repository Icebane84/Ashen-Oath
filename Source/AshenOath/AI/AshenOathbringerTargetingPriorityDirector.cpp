// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 788: Ashen Oathbringer Targeting Priority Director

#include "AshenOathbringerTargetingPriorityDirector.h"

AActor* UAshenOathbringerTargetingPriorityDirector::SelectHighPriorityCleaveTarget(TArray<AActor*> NearbyEnemies)
{
	if (NearbyEnemies.Num() == 0) return nullptr;

	AActor* BestTarget = NearbyEnemies[0];
	const float PriorityScore = 95.0f;

	OnCleaveTargetSelected.Broadcast(BestTarget, PriorityScore);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerTargetingPriorityDirector: CLEAVE TARGET SELECTED -> Enemy: '%s' | Priority Score: %.1f."),
		*BestTarget->GetName(), PriorityScore);

	return BestTarget;
}
