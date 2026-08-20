// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenHeartstoneReflectionUIBridgeComponent.h"

UAshenHeartstoneReflectionUIBridgeComponent::UAshenHeartstoneReflectionUIBridgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenHeartstoneReflectionUIBridgeComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenHeartstoneReflectionUIBridgeComponent: Heartstone reflection UI updated with state vector (Resolve: %.2f)"), NewState.Resolve);
}
