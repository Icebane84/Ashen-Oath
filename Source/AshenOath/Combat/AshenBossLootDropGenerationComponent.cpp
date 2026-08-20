// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenBossLootDropGenerationComponent.h"

UAshenBossLootDropGenerationComponent::UAshenBossLootDropGenerationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBossLootDropGenerationComponent::BeginPlay() { Super::BeginPlay(); }

int32 UAshenBossLootDropGenerationComponent::GenerateBossLootDrops()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBossLootDropGenerationComponent: Generated %d Eldrin memory shards and radiant inquisitorial relics!"), GuaranteedMemoryShards);
	return GuaranteedMemoryShards;
}
