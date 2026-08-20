// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenEldrinMemoryDuelTransitionComponent.h"

UAshenEldrinMemoryDuelTransitionComponent::UAshenEldrinMemoryDuelTransitionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEldrinMemoryDuelTransitionComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenEldrinMemoryDuelTransitionComponent::InitiateMemoryDuelTransition(FVector MindscapeArenaLocation)
{
	bIsInMindscapeArena = true;
	if (OnMemoryDuelTransitionStarted.IsBound())
	{
		OnMemoryDuelTransitionStarted.Broadcast(MindscapeArenaLocation);
	}
	UE_LOG(LogTemp, Warning, TEXT("UAshenEldrinMemoryDuelTransitionComponent: Eldrin Memory Duel transition initiated! Mindscape Arena at (%f, %f, %f)"),
		MindscapeArenaLocation.X, MindscapeArenaLocation.Y, MindscapeArenaLocation.Z);
	return true;
}
