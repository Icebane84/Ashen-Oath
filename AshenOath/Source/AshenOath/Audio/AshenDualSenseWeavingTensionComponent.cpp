// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDualSenseWeavingTensionComponent.h"

UAshenDualSenseWeavingTensionComponent::UAshenDualSenseWeavingTensionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TriggerMotorResistance = 0.0f;
}
void UAshenDualSenseWeavingTensionComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDualSenseWeavingTensionComponent::UpdateTriggerTension(float TensionScalar, EFilamentTensionState State)
{
	TriggerMotorResistance = FMath::Clamp(TensionScalar, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDualSenseWeavingTensionComponent: DualSense Trigger Motor Resistance: %.2f (State: %d)"),
		TriggerMotorResistance, static_cast<int32>(State));
}
