// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenVisualShiftNarrativeReactivityComponent.h"

UAshenVisualShiftNarrativeReactivityComponent::UAshenVisualShiftNarrativeReactivityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenVisualShiftNarrativeReactivityComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenVisualShiftNarrativeReactivityComponent::EvaluateNPCFearReaction(float CorruptionIntensity)
{
	const bool bFearTriggered = CorruptionIntensity > 0.60f;
	UE_LOG(LogTemp, Log, TEXT("UAshenVisualShiftNarrativeReactivityComponent: NPC fear reaction evaluated for corruption %.2f -> %s"),
		CorruptionIntensity, bFearTriggered ? TEXT("FEAR TRIGGERED") : TEXT("CALM"));
	return bFearTriggered;
}
