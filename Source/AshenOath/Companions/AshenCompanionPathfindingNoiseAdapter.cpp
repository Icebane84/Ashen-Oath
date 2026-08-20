// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionPathfindingNoiseAdapter.h"

UAshenCompanionPathfindingNoiseAdapter::UAshenCompanionPathfindingNoiseAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionPathfindingNoiseAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCompanionPathfindingNoiseAdapter::EvaluatePathfindingNoise(EAshenIntegrationDebtStage Stage)
{
	// ENGINE-SPEC-001 Section 2: Runtime Noise adds 200ms (0.2s) simulated pathfinding decision delay
	if (Stage == EAshenIntegrationDebtStage::RuntimeNoise || Stage == EAshenIntegrationDebtStage::ForcedCollapse)
	{
		PathfindingDecisionDelaySeconds = 0.20f;
	}
	else
	{
		PathfindingDecisionDelaySeconds = 0.0f;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionPathfindingNoiseAdapter: Pathfinding decision delay set to %.2fs for stage %d"),
		PathfindingDecisionDelaySeconds, (int32)Stage);
}
