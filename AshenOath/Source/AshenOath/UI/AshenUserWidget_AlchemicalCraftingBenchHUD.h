// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenUserWidget_AlchemicalCraftingBenchHUD.generated.h"

/**
 * UAshenUserWidget_AlchemicalCraftingBenchHUD
 * Campfire workstation UI for compounding gathered raw bases and catalysts into active alchemical matrices.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_AlchemicalCraftingBenchHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsCraftingBenchOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SetCraftingBenchVisibility(bool bOpen);
};
