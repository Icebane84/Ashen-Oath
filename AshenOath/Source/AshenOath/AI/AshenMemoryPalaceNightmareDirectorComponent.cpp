// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenMemoryPalaceNightmareDirectorComponent.h"

UAshenMemoryPalaceNightmareDirectorComponent::UAshenMemoryPalaceNightmareDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	NightmareSpawnThreshold = 0.60f;
}
void UAshenMemoryPalaceNightmareDirectorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenMemoryPalaceNightmareDirectorComponent::ShouldSpawnNightmareShade(float LocalTraumaDensity) const
{
	const bool bShouldSpawn = LocalTraumaDensity >= NightmareSpawnThreshold;
	if (bShouldSpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryPalaceNightmareDirectorComponent: High Trauma Density (%.2f >= %.2f) triggered Nightmare Shade ambush!"),
			LocalTraumaDensity, NightmareSpawnThreshold);
	}
	return bShouldSpawn;
}
