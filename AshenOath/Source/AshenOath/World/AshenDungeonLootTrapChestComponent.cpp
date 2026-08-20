// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 291: Ashen Dungeon Loot Trap Chest Component

#include "AshenDungeonLootTrapChestComponent.h"
#include "AshenOath_HealthComponent.h"

UAshenDungeonLootTrapChestComponent::UAshenDungeonLootTrapChestComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TrapExplosionDamage = 180.0f;
	bIsSprung = false;
}

void UAshenDungeonLootTrapChestComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDungeonLootTrapChestComponent::TriggerChest(AActor* OpeningActor)
{
	if (bIsSprung) return false;

	bIsSprung = true;

	if (OpeningActor)
	{
		UAshenOath_HealthComponent* HealthComp = OpeningActor->FindComponentByClass<UAshenOath_HealthComponent>();
		if (HealthComp)
		{
			HealthComp->ReceiveDamage(TrapExplosionDamage, GetOwner());
		}
	}

	const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
	OnTrapChestSprung.Broadcast(TrapExplosionDamage, Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonLootTrapChestComponent: TRAP CHEST SPRUNG at (%.0f, %.0f, %.0f) — Dealt %.0f Trap Damage to '%s'."),
		Location.X, Location.Y, Location.Z, TrapExplosionDamage, OpeningActor ? *OpeningActor->GetName() : TEXT("Unknown"));

	return true;
}
