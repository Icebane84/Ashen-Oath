// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASAttributeRegenRateModulatorComponent.h"

UAshenGASAttributeRegenRateModulatorComponent::UAshenGASAttributeRegenRateModulatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASAttributeRegenRateModulatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	RegenRateMultiplier = FMath::Clamp(1.0f - (NewState.IntegrationDebt * 0.5f), 0.3f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASAttributeRegenRateModulatorComponent: Attribute regen rate multiplier set to %.2f"), RegenRateMultiplier);
}
