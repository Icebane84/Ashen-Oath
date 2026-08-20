// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenUserWidget_AlchemicalCraftingHUD.generated.h"

/**
 * UAshenUserWidget_AlchemicalCraftingHUD
 * Diegetic field journal crafting HUD with Material Pouches (left), Clockwork Assembly Wheel (center), and Garrett Marginalia (right).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_AlchemicalCraftingHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 DisplayedGloomwoodSap = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 DisplayedGhostbloom = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 DisplayedSulfurDust = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAlchemicalItemType SelectedRecipe = EAlchemicalItemType::GloomwoodTripwire;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateCraftingHUD(int32 InSap, int32 InBloom, int32 InSulfur, EAlchemicalItemType InRecipe);
};
