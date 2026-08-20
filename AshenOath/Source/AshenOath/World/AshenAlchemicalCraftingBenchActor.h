// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAlchemicalCraftingBenchActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemCraftedAtBenchSignature, FName, RecipeID, int32, QuantityCrafted);

/**
 * AAshenAlchemicalCraftingBenchActor
 *
 * World Actor for Garrett's sanctuary crafting bench.
 */
UCLASS()
class ASHENOATH_API AAshenAlchemicalCraftingBenchActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenAlchemicalCraftingBenchActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CraftingBench")
	bool CraftRecipeAtBench(FName RecipeID, int32 Quantity = 1);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CraftingBench|Events")
	FOnItemCraftedAtBenchSignature OnItemCrafted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CraftingBench")
	int32 TotalItemsCrafted = 0;
};
