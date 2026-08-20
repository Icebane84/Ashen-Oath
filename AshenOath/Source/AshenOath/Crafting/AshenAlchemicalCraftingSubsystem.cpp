// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Crafting/AshenAlchemicalCraftingSubsystem.h"

void UAshenAlchemicalCraftingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	StockpileGloomwoodSap = 3;
	StockpileGhostbloom = 2;
	StockpileSulfurDust = 4;
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalCraftingSubsystem: Alchemical Crafting Subsystem initialized."));
}
void UAshenAlchemicalCraftingSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenAlchemicalCraftingSubsystem::AddReagent(EAlchemicalReagent Reagent, int32 Amount)
{
	if (Amount <= 0) return;
	switch (Reagent)
	{
	case EAlchemicalReagent::GloomwoodSap:
		StockpileGloomwoodSap += Amount;
		break;
	case EAlchemicalReagent::Ghostbloom:
		StockpileGhostbloom += Amount;
		break;
	case EAlchemicalReagent::SulfurDust:
		StockpileSulfurDust += Amount;
		break;
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalCraftingSubsystem: Added %d reagents of type %d."), Amount, static_cast<int32>(Reagent));
}

bool UAshenAlchemicalCraftingSubsystem::CanCraftRecipe(const FAlchemicalRecipe& Recipe) const
{
	return (StockpileGloomwoodSap >= Recipe.RequiredGloomwoodSap) &&
	       (StockpileGhostbloom >= Recipe.RequiredGhostbloom) &&
	       (StockpileSulfurDust >= Recipe.RequiredSulfurDust);
}

bool UAshenAlchemicalCraftingSubsystem::ExecuteCraftRecipe(const FAlchemicalRecipe& Recipe)
{
	if (!CanCraftRecipe(Recipe)) return false;

	StockpileGloomwoodSap -= Recipe.RequiredGloomwoodSap;
	StockpileGhostbloom -= Recipe.RequiredGhostbloom;
	StockpileSulfurDust -= Recipe.RequiredSulfurDust;

	UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalCraftingSubsystem: Crafted Item %d (Output: %d). Stockpile Remaining: Sap=%d, Bloom=%d, Sulfur=%d"),
		static_cast<int32>(Recipe.ItemType), Recipe.OutputQuantity, StockpileGloomwoodSap, StockpileGhostbloom, StockpileSulfurDust);

	return true;
}
