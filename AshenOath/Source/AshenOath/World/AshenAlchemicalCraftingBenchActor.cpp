// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 583: Ashen Alchemical Crafting Bench Actor

#include "AshenAlchemicalCraftingBenchActor.h"

AAshenAlchemicalCraftingBenchActor::AAshenAlchemicalCraftingBenchActor()
{
	PrimaryActorTick.bCanEverTick = false;
	TotalItemsCrafted = 0;
}

bool AAshenAlchemicalCraftingBenchActor::CraftRecipeAtBench(FName RecipeID, int32 Quantity)
{
	if (RecipeID.IsNone()) return false;

	TotalItemsCrafted += Quantity;
	OnItemCrafted.Broadcast(RecipeID, Quantity);

	UE_LOG(LogTemp, Warning, TEXT("AAshenAlchemicalCraftingBenchActor: RECIPE CRAFTED AT BENCH -> '%s' (Qty: %d | Total: %d)."),
		*RecipeID.ToString(), Quantity, TotalItemsCrafted);

	return true;
}
