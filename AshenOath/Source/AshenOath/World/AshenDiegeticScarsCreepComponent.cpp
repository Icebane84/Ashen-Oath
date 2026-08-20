// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDiegeticScarsCreepComponent.h"

UAshenDiegeticScarsCreepComponent::UAshenDiegeticScarsCreepComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticScarsCreepComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ScarEmissiveIntensity = FMath::Clamp((NewState.Corruption * 3.0f) + ((1.0f - NewState.Resolve) * 2.0f), 0.0f, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticScarsCreepComponent: Scar emissive intensity updated to %.2f"), ScarEmissiveIntensity);
}
