// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenUserWidget_SanctuarySurvivalHUD.generated.h"

/**
 * UAshenUserWidget_SanctuarySurvivalHUD
 * 
 * Renders the survival HUD: Body temperature gauge (Celsius), shelter tier badge, active meal immunity countdown timer, and Forensic Journal prompt.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SanctuarySurvivalHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_SanctuarySurvivalHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed survival metrics */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Survival")
	void UpdateSurvivalHUD(
		float BodyTempC,
		EThermalShelterTier ShelterTier,
		ECookedMealBuffType ActiveMeal,
		float MealDurationRemaining);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Survival")
	float DisplayedBodyTempC = 37.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Survival")
	EThermalShelterTier DisplayedShelterTier = EThermalShelterTier::OpenWilderness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Survival")
	ECookedMealBuffType DisplayedMeal = ECookedMealBuffType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Survival")
	float DisplayedMealDuration = 0.0f;
};
