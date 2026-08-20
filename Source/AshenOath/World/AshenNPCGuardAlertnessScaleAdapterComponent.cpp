// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCGuardAlertnessScaleAdapterComponent.h"

UAshenNPCGuardAlertnessScaleAdapterComponent::UAshenNPCGuardAlertnessScaleAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCGuardAlertnessScaleAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	GuardAlertnessMultiplier = 1.0f + (NewState.Corruption * 1.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCGuardAlertnessScaleAdapterComponent: Guard alertness multiplier set to %.2f"), GuardAlertnessMultiplier);
}
