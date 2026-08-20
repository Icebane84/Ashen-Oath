// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDualSenseAdaptiveTriggerComponent.h"

UAshenDualSenseAdaptiveTriggerComponent::UAshenDualSenseAdaptiveTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	L2TriggerResistanceScalar = 0.0f;
}
void UAshenDualSenseAdaptiveTriggerComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDualSenseAdaptiveTriggerComponent::UpdateTriggerResistance(float SerafinaBurnoutScalar)
{
	L2TriggerResistanceScalar = FMath::Clamp(SerafinaBurnoutScalar, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDualSenseAdaptiveTriggerComponent: L2 Adaptive Trigger Resistance: %.2f (Serafina Burnout: %.2f)"),
		L2TriggerResistanceScalar, SerafinaBurnoutScalar);
}
