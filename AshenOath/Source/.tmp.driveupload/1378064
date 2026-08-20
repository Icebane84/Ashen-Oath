// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenPsychologicalFinisherImpactComponent.h"

UAshenPsychologicalFinisherImpactComponent::UAshenPsychologicalFinisherImpactComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenPsychologicalFinisherImpactComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenPsychologicalFinisherImpactComponent::ProcessExecutionDebtReduction()
{
	if (OnDebtReductionApplied.IsBound())
	{
		OnDebtReductionApplied.Broadcast(ExecutionDebtReductionValue);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenPsychologicalFinisherImpactComponent: Integration Debt reduced by -%.2f via execution finisher!"), ExecutionDebtReductionValue);
	return ExecutionDebtReductionValue;
}
