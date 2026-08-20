// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSymbioticResonanceEvaluatorComponent.h"

UAshenSymbioticResonanceEvaluatorComponent::UAshenSymbioticResonanceEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsResonanceActive = false;
}
void UAshenSymbioticResonanceEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenSymbioticResonanceEvaluatorComponent::SetResonanceState(bool bActive)
{
	bIsResonanceActive = bActive;
	if (bIsResonanceActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSymbioticResonanceEvaluatorComponent: SYMBIOTIC RESONANCE ACTIVE! HUD Suppressed -> Frictionless Frame-Lock Unlocked!"));
	}
}
