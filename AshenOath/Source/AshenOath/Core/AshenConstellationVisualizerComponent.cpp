// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenConstellationVisualizerComponent.h"
#include "AshenSoulPerkActivationComponent.h"
#include "GameFramework/Actor.h"

UAshenConstellationVisualizerComponent::UAshenConstellationVisualizerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveNodeCount = 0;
}

void UAshenConstellationVisualizerComponent::BeginPlay()
{
	Super::BeginPlay();
}

float UAshenConstellationVisualizerComponent::CalculateConstellationGlow(FName NodeID)
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return 0.2f;

	if (UAshenSoulPerkActivationComponent* Perks = OwnerActor->FindComponentByClass<UAshenSoulPerkActivationComponent>())
	{
		if (Perks->IsPerkActive(NodeID))
		{
			return 1.0f; // Active emissive glow
		}
	}

	return 0.2f; // Dim locked node glow
}

void UAshenConstellationVisualizerComponent::RefreshConstellationVisuals()
{
	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return;

	if (UAshenSoulPerkActivationComponent* Perks = OwnerActor->FindComponentByClass<UAshenSoulPerkActivationComponent>())
	{
		ActiveNodeCount = Perks->ActivePerkIds.Num();
	}

	OnVisualsRefreshed.Broadcast(ActiveNodeCount);
	UE_LOG(LogTemp, Log, TEXT("UAshenConstellationVisualizerComponent: Constellation visuals refreshed (%d active nodes)."), ActiveNodeCount);
}
