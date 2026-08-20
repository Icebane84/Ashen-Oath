// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenStaggerStateEvaluatorComponent.h"

UAshenStaggerStateEvaluatorComponent::UAshenStaggerStateEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenStaggerStateEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenStaggerStateEvaluatorComponent::TriggerExecutionStaggerWindow(float DurationSeconds)
{
	bIsStaggeredForExecution = true;
	if (OnStaggeredStateChanged.IsBound())
	{
		OnStaggeredStateChanged.Broadcast(true);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenStaggerStateEvaluatorComponent: Enemy STAGGERED! Execution window open for %.1fs"), DurationSeconds);
}
