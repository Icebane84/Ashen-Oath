// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenMindscapeTransitionPhenotypeEvaluator.h"

UAshenMindscapeTransitionPhenotypeEvaluator::UAshenMindscapeTransitionPhenotypeEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMindscapeTransitionPhenotypeEvaluator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	bTriggerMindscape = (NewState.Corruption >= 0.95f) && (NewState.Resolve <= 0.1f);
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeTransitionPhenotypeEvaluator: Mindscape transition criteria evaluated -> %s"),
		bTriggerMindscape ? TEXT("TRIGGERED") : TEXT("DORMANT"));
}
