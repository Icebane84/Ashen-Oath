// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenCircuitBreakerEvaluatorComponent.h"

UAshenCircuitBreakerEvaluatorComponent::UAshenCircuitBreakerEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CircuitBreakerThreshold = 0.15f;
}
void UAshenCircuitBreakerEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenCircuitBreakerEvaluatorComponent::ShouldTripCircuitBreaker(float CharacterUtilityScore) const
{
	const bool bTripped = (CharacterUtilityScore < CircuitBreakerThreshold);
	if (bTripped)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenCircuitBreakerEvaluatorComponent: CIRCUIT BREAKER TRIPPED! Utility: %.2f < %.2f -> Exploiting Vulnerability!"),
			CharacterUtilityScore, CircuitBreakerThreshold);
	}
	return bTripped;
}
