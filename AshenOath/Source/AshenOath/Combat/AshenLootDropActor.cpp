// Copyright Phoenix Protocol. All rights reserved.

#include "AshenLootDropActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Engine/World.h"

AAshenLootDropActor::AAshenLootDropActor()
{
	InteractionText = TEXT("Pick up item");

	LootMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LootMesh"));
	LootMesh->SetupAttachment(RootComponent);
	LootMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // let root box handle physics

	if (CollisionBox)
	{
		CollisionBox->SetSimulatePhysics(true);
		CollisionBox->SetCollisionProfileName(TEXT("PhysicsActor"));
		CollisionBox->SetGenerateOverlapEvents(true);
	}
}

void AAshenLootDropActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenLootDropActor::Interact_Implementation(APawn* Player)
{
	Super::Interact_Implementation(Player);

	if (!Player) return;

	// 1. Add item to player inventory
	if (Player->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_InventoryComponent* Inv = IAshenCharacterInterface::Execute_GetInventoryComponent(Player))
		{
			Inv->AddItem(LootItem);
		}
	}

	// 2. Broadcast global event
	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		if (UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>())
		{
			EventBus->BroadcastItemCollected(FName(*LootItem.ItemName));
		}
	}

	// 3. Destroy item pickup
	Destroy();
}
