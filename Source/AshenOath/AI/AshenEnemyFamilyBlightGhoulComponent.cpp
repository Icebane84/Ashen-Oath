// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 481: Ashen Enemy Family Blight Ghoul Component

#include "AshenEnemyFamilyBlightGhoulComponent.h"

UAshenEnemyFamilyBlightGhoulComponent::UAshenEnemyFamilyBlightGhoulComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveSwarmMemberCount = 1;
	CalculatedFlankMultiplier = 1.0f;
}

void UAshenEnemyFamilyBlightGhoulComponent::UpdateSwarmCoordination(int32 NearbyGhoulCount)
{
	ActiveSwarmMemberCount = FMath::Max(1, NearbyGhoulCount);
	CalculatedFlankMultiplier = 1.0f + (ActiveSwarmMemberCount * 0.15f);

	OnSwarmStateChanged.Broadcast(ActiveSwarmMemberCount, CalculatedFlankMultiplier);

	UE_LOG(LogTemp, Log, TEXT("UAshenEnemyFamilyBlightGhoulComponent: GHOUL SWARM COORDINATION — Members: %d | Flank Multiplier: %.2fx"),
		ActiveSwarmMemberCount, CalculatedFlankMultiplier);
}
