// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 738: Ashen Contested Memory Resolution Evaluator

#include "AshenContestedMemoryResolutionEvaluator.h"

UAshenContestedMemoryResolutionEvaluator::UAshenContestedMemoryResolutionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenContestedMemoryResolutionEvaluator::EvaluateMemoryResolution(FName MemoryTag, float GraceLensWeight, float AccountabilityLensWeight)
{
	const bool bStabilized = (GraceLensWeight >= AccountabilityLensWeight);
	OnResolutionEvaluated.Broadcast(MemoryTag, bStabilized);

	UE_LOG(LogTemp, Warning, TEXT("UAshenContestedMemoryResolutionEvaluator: CONTESTED MEMORY RESOLVED -> Node: '%s' | Grace: %.2f vs Acc: %.2f | Result: %s."),
		*MemoryTag.ToString(), GraceLensWeight, AccountabilityLensWeight, bStabilized ? TEXT("STABILIZED TRUTH") : TEXT("FRAGMENTED DOUBT"));

	return bStabilized;
}
