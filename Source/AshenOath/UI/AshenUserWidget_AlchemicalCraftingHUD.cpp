// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_AlchemicalCraftingHUD.h"

void UAshenUserWidget_AlchemicalCraftingHUD::UpdateCraftingHUD(int32 InSap, int32 InBloom, int32 InSulfur, EAlchemicalItemType InRecipe)
{
	DisplayedGloomwoodSap = InSap;
	DisplayedGhostbloom = InBloom;
	DisplayedSulfurDust = InSulfur;
	SelectedRecipe = InRecipe;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_AlchemicalCraftingHUD: Workstation HUD -> Sap: %d, Bloom: %d, Sulfur: %d, Recipe: %d"),
		DisplayedGloomwoodSap, DisplayedGhostbloom, DisplayedSulfurDust, static_cast<int32>(SelectedRecipe));
}
