// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenLootDropActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenLootDropActor
 * Physical loot item that can be dropped by enemies and collected by the wielder.
 */
UCLASS()
class ASHENOATH_API AAshenLootDropActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenLootDropActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Interact_Implementation(APawn* Player) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* LootMesh;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loot Settings")
	FAshenItemData LootItem;
};
