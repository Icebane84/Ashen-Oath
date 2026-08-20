// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettTrapNetworkComponent.h"

UAshenGarrettTrapNetworkComponent::UAshenGarrettTrapNetworkComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettTrapNetworkComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenGarrettTrapNetworkComponent::RegisterTrapToNetwork()
{
	LinkedTrapCount++;
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTrapNetworkComponent: Trap registered. Network size: %d"), LinkedTrapCount);
}

bool UAshenGarrettTrapNetworkComponent::RegisterTrap(FName TrapID, FVector Location)
{
	if (ActiveTrapIDs.Num() >= MaxActiveTrapSlots)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettTrapNetworkComponent: Cannot register trap %s — max slots (%d) reached."),
			*TrapID.ToString(), MaxActiveTrapSlots);
		return false;
	}

	ActiveTrapIDs.Add(TrapID);
	LinkedTrapCount = ActiveTrapIDs.Num();
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTrapNetworkComponent: Trap %s registered at (%f, %f, %f). Total: %d"),
		*TrapID.ToString(), Location.X, Location.Y, Location.Z, LinkedTrapCount);
	return true;
}

bool UAshenGarrettTrapNetworkComponent::DeregisterTrap(FName TrapID)
{
	const int32 Removed = ActiveTrapIDs.Remove(TrapID);
	LinkedTrapCount = ActiveTrapIDs.Num();
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTrapNetworkComponent: Trap %s deregistered. Remaining: %d"),
		*TrapID.ToString(), LinkedTrapCount);
	return Removed > 0;
}

int32 UAshenGarrettTrapNetworkComponent::GetActiveTrapCount() const
{
	return ActiveTrapIDs.Num() > 0 ? ActiveTrapIDs.Num() : LinkedTrapCount;
}

int32 UAshenGarrettTrapNetworkComponent::TriggerNetworkCascade()
{
	const int32 Detonated = GetActiveTrapCount();
	ActiveTrapIDs.Empty();
	LinkedTrapCount = 0;
	if (OnTrapCascadeTriggered.IsBound())
	{
		OnTrapCascadeTriggered.Broadcast(Detonated);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettTrapNetworkComponent: Cascade detonation triggered across %d linked traps!"), Detonated);
	return Detonated;
}
