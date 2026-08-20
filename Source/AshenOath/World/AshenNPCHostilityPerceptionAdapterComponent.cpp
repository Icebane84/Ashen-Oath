// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenNPCHostilityPerceptionAdapterComponent.h"

UAshenNPCHostilityPerceptionAdapterComponent::UAshenNPCHostilityPerceptionAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCHostilityPerceptionAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	GuardPerceptionRadiusScalar = 1.0f + (NewState.Corruption * 0.8f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCHostilityPerceptionAdapterComponent: Guard perception radius scalar set to %.2f"), GuardPerceptionRadiusScalar);
}
