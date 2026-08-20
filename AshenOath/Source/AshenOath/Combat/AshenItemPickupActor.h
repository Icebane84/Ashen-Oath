// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenItemPickupActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class URotatingMovementComponent;

/**
 * AAshenItemPickupActor
 *
 * World-space item pickup with a floating rotation and auto-collect
 * on player proximity (200 unit radius). Adds item data directly to
 * the player's inventory component on Interact.
 */
UCLASS()
class ASHENOATH_API AAshenItemPickupActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenItemPickupActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Interact_Implementation(APawn* Player) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Pickup")
	FAshenItemData ItemData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> PickupMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> ProximityCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<URotatingMovementComponent> RotatingMovement;

private:
	bool bCollected = false;
};
