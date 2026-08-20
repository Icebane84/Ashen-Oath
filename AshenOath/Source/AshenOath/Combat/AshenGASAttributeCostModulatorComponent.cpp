// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASAttributeCostModulatorComponent.h"

UAshenGASAttributeCostModulatorComponent::UAshenGASAttributeCostModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASAttributeCostModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	StaminaCostMultiplier = FMath::Clamp(1.2f - (NewState.Resolve * 0.4f), 0.7f, 1.3f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASAttributeCostModulatorComponent: Stamina cost multiplier set to %.2f"), StaminaCostMultiplier);
}
