// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CraftingEmberForge.generated.h"

/**
 * UAshenUserWidget_CraftingEmberForge
 *
 * UMG backing widget rendering merchant crafting menus and Ember exchange rates.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CraftingEmberForge : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateCraftingDisplay(FName ItemID, float EmberCost);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedCraftItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedCost = 0.0f;
};
