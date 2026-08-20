// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenFlowCounterGASAbility.h"

UAshenFlowCounterGASAbility::UAshenFlowCounterGASAbility()
{
	TimeDilationFactor = 0.35f;
	DilationDuration = 1.5f;
}

bool UAshenFlowCounterGASAbility::TriggerFlowCounter(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenFlowCounterGASAbility: FLOW COUNTER TRIGGERED! (World Dilation: %.2fx for %.1fs)."),
		TimeDilationFactor, DilationDuration);
	return true;
}
