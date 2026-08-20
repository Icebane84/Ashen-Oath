// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_LootComponent.generated.h"

class AAshenLootDropActor;

/**
 * UAshenOath_LootComponent
 * Attached to enemies. Awards experience points (XP) to the player
 * and spawns physical items upon the owner's death.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_LootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_LootComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Award wielder XP and roll drop check to spawn physical loot drop actor */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Loot")
	void SpawnLoot();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot Settings")
	int32 XpValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot Settings")
	TArray<FAshenItemData> LootTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot Settings", meta = (ClampMin = 0.0, ClampMax = 1.0))
	float DropChance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Loot Settings")
	TSubclassOf<AAshenLootDropActor> LootDropClass;
};
