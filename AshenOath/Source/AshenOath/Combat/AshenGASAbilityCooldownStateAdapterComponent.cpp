// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASAbilityCooldownStateAdapterComponent.h"

UAshenGASAbilityCooldownStateAdapterComponent::UAshenGASAbilityCooldownStateAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASAbilityCooldownStateAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	CooldownMultiplier = FMath::Clamp(1.0f + (NewState.IntegrationDebt * 0.5f), 1.0f, 1.6f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASAbilityCooldownStateAdapterComponent: GAS ability cooldown multiplier set to %.2f"), CooldownMultiplier);
}
