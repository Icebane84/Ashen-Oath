// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 286: Ashen Dungeon Secret Passage Component

#include "AshenDungeonSecretPassageComponent.h"

UAshenDungeonSecretPassageComponent::UAshenDungeonSecretPassageComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsRevealed = false;
}

void UAshenDungeonSecretPassageComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDungeonSecretPassageComponent::RevealPassage()
{
	if (bIsRevealed) return true;

	bIsRevealed = true;
	const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;

	OnSecretPassageRevealed.Broadcast(Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonSecretPassageComponent: SECRET PASSAGE REVEALED at (%.0f, %.0f, %.0f)."),
		Location.X, Location.Y, Location.Z);

	return true;
}
