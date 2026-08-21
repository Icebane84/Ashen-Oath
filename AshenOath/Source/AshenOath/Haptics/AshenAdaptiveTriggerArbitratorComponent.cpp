// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Haptics/AshenAdaptiveTriggerArbitratorComponent.h"

UAshenAdaptiveTriggerArbitratorComponent::UAshenAdaptiveTriggerArbitratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FDualSenseTriggerConfig UAshenAdaptiveTriggerArbitratorComponent::ArbitrateTriggerRequest(
	const FDualSenseTriggerConfig& CurrentConfig,
	const FDualSenseTriggerConfig& IncomingRequest) const
{
	if (ShouldOverride(CurrentConfig.Priority, IncomingRequest.Priority))
	{
		return IncomingRequest;
	}

	return CurrentConfig;
}

bool UAshenAdaptiveTriggerArbitratorComponent::ShouldOverride(
	ETriggerPriorityLevel CurrentPriority,
	ETriggerPriorityLevel IncomingPriority) const
{
	// Priority 1 (Dialogue Lockout) > Priority 2 (Combat Stagger) > Priority 3 (Ambient Somatic)
	// Lower enum integer value corresponds to higher gameplay priority
	return static_cast<uint8>(IncomingPriority) >= static_cast<uint8>(CurrentPriority);
}
