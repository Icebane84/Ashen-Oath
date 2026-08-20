// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 167: Ashen Item Pickup Actor

#include "AshenItemPickupActor.h"
#include "AshenOath_InventoryComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Pawn.h"

AAshenItemPickupActor::AAshenItemPickupActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bCollected = false;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	SetRootComponent(PickupMesh);
	PickupMesh->SetCollisionProfileName(TEXT("NoCollision"));

	ProximityCollider = CreateDefaultSubobject<USphereComponent>(TEXT("ProximityCollider"));
	ProximityCollider->SetupAttachment(PickupMesh);
	ProximityCollider->SetSphereRadius(200.0f);
	ProximityCollider->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0.0f, 90.0f, 0.0f);
}

void AAshenItemPickupActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenItemPickupActor::Interact_Implementation(APawn* Player)
{
	if (bCollected || !Player) return;

	UAshenOath_InventoryComponent* Inventory = Player->FindComponentByClass<UAshenOath_InventoryComponent>();
	if (!Inventory)
	{
		UE_LOG(LogTemp, Warning, TEXT("AAshenItemPickupActor: Player has no InventoryComponent — pickup skipped."));
		return;
	}

	Inventory->AddItem(ItemData);
	bCollected = true;

	UE_LOG(LogTemp, Warning, TEXT("AAshenItemPickupActor: Item '%s' collected by '%s' — destroying pickup."),
		*ItemData.ItemName, *Player->GetName());

	Destroy();
}
