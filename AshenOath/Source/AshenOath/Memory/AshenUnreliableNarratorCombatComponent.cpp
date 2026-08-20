// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenUnreliableNarratorCombatComponent.h"

UAshenUnreliableNarratorCombatComponent::UAshenUnreliableNarratorCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenUnreliableNarratorCombatComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenUnreliableNarratorCombatComponent::SpawnCombatMirage(FVector Position)
{
	ActiveMirageCount++;
	ActivePhantomCount++;
	if (OnMirageFoeSpawned.IsBound())
	{
		OnMirageFoeSpawned.Broadcast(Position);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenUnreliableNarratorCombatComponent: Phantom combat mirage spawned at (%f, %f, %f). Active: %d"),
		Position.X, Position.Y, Position.Z, ActiveMirageCount);
	return true;
}

bool UAshenUnreliableNarratorCombatComponent::SpawnPhantomEnemyVisual(FVector Position, float Duration)
{
	return SpawnCombatMirage(Position);
}
