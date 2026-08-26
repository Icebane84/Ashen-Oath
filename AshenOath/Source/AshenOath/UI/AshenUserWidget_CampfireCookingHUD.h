// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenUserWidget_CampfireCookingHUD.generated.h"

/**
 * UAshenUserWidget_CampfireCookingHUD
 * 
 * UMG widget presenting the campfire cooking cauldron interface, boiling thermometer, stirring rhythm prompt, and ration freshness.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CampfireCookingHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_CampfireCookingHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed pot telemetry and recipe progress */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Cooking")
	void UpdateCookingHUD(const FCampfireStewStateVector& State);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Cooking")
	FCampfireStewStateVector DisplayedPotState;
};
