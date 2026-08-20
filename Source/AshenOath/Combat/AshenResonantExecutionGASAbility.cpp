// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenResonantExecutionGASAbility.h"

UAshenResonantExecutionGASAbility::UAshenResonantExecutionGASAbility()
{
	CinematicTimeDilation = 0.15f;
	ImpactHoldDuration = 2.0f;
}

bool UAshenResonantExecutionGASAbility::InitiateResonantExecution(AActor* InstigatorActor)
{
	if (!InstigatorActor) return false;
	UE_LOG(LogTemp, Warning, TEXT("UAshenResonantExecutionGASAbility: Initiated Resonant Execution (Dilation: %.2fx, Hold Duration: %.1fs)."),
		CinematicTimeDilation, ImpactHoldDuration);
	return true;
}
