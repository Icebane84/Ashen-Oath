// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalCraftingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAlchemicalCraftedSignature, FName, RecipeId, bool, bSuccess);

/**
 * UAshenAlchemicalCraftingComponent
 *
 * Garrett's alchemical crafting and consumable refill station component.
 * Manages raw ingredient storage (Sulfur Dust, Ghostbloom Petals, Ember Ash)
 * and refills quickbar slots at Sanctuary Haven stations.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalCraftingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAlchemicalCraftingComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Ingredient Inventory ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemy")
	void AddIngredient(FName IngredientId, int32 Quantity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Alchemy")
	int32 GetIngredientQuantity(FName IngredientId) const;

	// --- Crafting API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemy")
	bool CraftRecipe(FName RecipeId, AActor* PlayerPawn);

	// --- Ingredient Pouch ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Alchemy")
	TMap<FName, int32> IngredientPouch;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Alchemy|Events")
	FOnAlchemicalCraftedSignature OnItemCrafted;
};
