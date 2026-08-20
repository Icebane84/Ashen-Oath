// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenUserWidget_AlchemicalPouchHUD.generated.h"

/**
 * UAshenUserWidget_AlchemicalPouchHUD
 * Diegetic HUD displaying Garrett's remaining finite inventory: Burning Steel oils, Gloomwood needles, smoke balms, flares, and caltrops.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_AlchemicalPouchHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FAlchemicalInventoryPouch DisplayPouch;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdatePouchTelemetry(const FAlchemicalInventoryPouch& InPouch);
};
