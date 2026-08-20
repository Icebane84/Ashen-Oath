// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenLootDropComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEnemyLootDroppedSignature, AActor*, EnemyActor, float, EmbersGranted, FName, ReagentGranted);

/**
 * UAshenLootDropComponent
 *
 * Attached to enemy pawns to govern loot generation upon death.
 * Grants currency Embers (UAshenOath_CurrencyComponent) and alchemical reagents
 * (UAshenAlchemicalCraftingComponent) to the killing player character.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLootDropComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenLootDropComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Loot")
	float EmberRewardAmount = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Loot")
	FName AlchemicalReagentId = FName("SulfurDust");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Loot")
	int32 ReagentQuantity = 1;

	/** Triggers loot generation upon enemy death. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Loot")
	void TriggerLootDrop(AActor* KillerActor);

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Loot|Events")
	FOnEnemyLootDroppedSignature OnLootDropped;
};
