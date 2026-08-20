// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASEffectStaggerThresholdModulatorComponent.h"

UAshenGASEffectStaggerThresholdModulatorComponent::UAshenGASEffectStaggerThresholdModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASEffectStaggerThresholdModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	StaggerPoiseMultiplier = 1.0f - (NewState.Corruption * 0.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASEffectStaggerThresholdModulatorComponent: Stagger poise multiplier set to %.2f"), StaggerPoiseMultiplier);
}
