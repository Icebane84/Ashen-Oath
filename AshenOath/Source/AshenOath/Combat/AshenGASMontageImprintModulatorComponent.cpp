// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASMontageImprintModulatorComponent.h"

UAshenGASMontageImprintModulatorComponent::UAshenGASMontageImprintModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASMontageImprintModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	PlayRateMultiplier = FMath::Clamp(0.85f + (NewState.Resolve * 0.3f), 0.7f, 1.25f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASMontageImprintModulatorComponent: GAS attack montage play rate multiplier set to %.2f"), PlayRateMultiplier);
}
