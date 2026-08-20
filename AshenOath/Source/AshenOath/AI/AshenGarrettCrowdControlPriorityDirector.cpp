// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 709: Ashen Garrett Crowd Control Priority Director

#include "AshenGarrettCrowdControlPriorityDirector.h"

AActor* UAshenGarrettCrowdControlPriorityDirector::SelectHighPriorityCCTarget(TArray<AActor*> NearbyEnemies, AActor* ThreatTargetActor)
{
	if (NearbyEnemies.Num() == 0) return nullptr;

	AActor* BestTarget = NearbyEnemies[0];
	const float PriorityScore = 95.0f; // High priority CC calculation

	OnCCPriorityEvaluated.Broadcast(BestTarget, PriorityScore);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettCrowdControlPriorityDirector: CC PRIORITY EVALUATED -> Selected Target: '%s' | Score: %.0f."),
		*BestTarget->GetName(), PriorityScore);

	return BestTarget;
}
