// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettTripwireComponent.h"

UAshenGarrettTripwireComponent::UAshenGarrettTripwireComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettTripwireComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenGarrettTripwireComponent::DeployTripwire(FVector AnchorA, FVector AnchorB)
{
	ActiveTripwireCount++;
	if (OnTripwireDeployed.IsBound())
	{
		OnTripwireDeployed.Broadcast(AnchorA, AnchorB);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettTripwireComponent: Tension tripwire deployed between anchors. Total active: %d"), ActiveTripwireCount);
	return true;
}
