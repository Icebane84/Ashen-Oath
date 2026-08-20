// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 276: Ashen Dungeon Destructible Wall Component

#include "AshenDungeonDestructibleWallComponent.h"

UAshenDungeonDestructibleWallComponent::UAshenDungeonDestructibleWallComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxWallHealth = 250.0f;
	CurrentHealth = 250.0f;
	bIsDestroyed = false;
}

void UAshenDungeonDestructibleWallComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxWallHealth;
}

void UAshenDungeonDestructibleWallComponent::ReceiveStructuralDamage(float DamageAmount)
{
	if (bIsDestroyed) return;

	CurrentHealth = FMath::Max(0.0f, CurrentHealth - DamageAmount);

	if (CurrentHealth <= 0.0f)
	{
		bIsDestroyed = true;
		const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;

		OnWallDestroyed.Broadcast(Location);

		UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonDestructibleWallComponent: WALL CRUMBLED at (%.0f, %.0f, %.0f)."),
			Location.X, Location.Y, Location.Z);
	}
}
