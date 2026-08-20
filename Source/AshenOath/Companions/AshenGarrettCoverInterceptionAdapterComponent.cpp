// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettCoverInterceptionAdapterComponent.h"

UAshenGarrettCoverInterceptionAdapterComponent::UAshenGarrettCoverInterceptionAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettCoverInterceptionAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	InterceptionThreshold = FMath::Clamp(NewState.GarrettTrust, 0.1f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettCoverInterceptionAdapterComponent: Garrett cover interception threshold updated to %.2f"), InterceptionThreshold);
}
