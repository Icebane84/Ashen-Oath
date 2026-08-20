// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 197: Ashen Soul Constellation Visualizer Component

#include "AshenSoulConstellationVisualizerComponent.h"

UAshenSoulConstellationVisualizerComponent::UAshenSoulConstellationVisualizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	NodeGlowMultiplier = 0.15f;
	ActiveNodeCount = 0;
	TotalGlowIntensity = 1.0f;
}

void UAshenSoulConstellationVisualizerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSoulConstellationVisualizerComponent::RefreshVisuals(int32 UnlockedNodesCount, float BaseGlowIntensity)
{
	ActiveNodeCount = FMath::Max(0, UnlockedNodesCount);
	TotalGlowIntensity = BaseGlowIntensity + (ActiveNodeCount * NodeGlowMultiplier);

	OnVisualsUpdated.Broadcast(ActiveNodeCount, TotalGlowIntensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSoulConstellationVisualizerComponent: Constellation Visuals REFRESHED — %d nodes unlocked, total glow intensity: %.2f."),
		ActiveNodeCount, TotalGlowIntensity);
}
