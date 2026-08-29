// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_SanctuarySurvivalHUD.h"

UAshenUserWidget_SanctuarySurvivalHUD::UAshenUserWidget_SanctuarySurvivalHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedBodyTempC = 37.0f;
	DisplayedShelterTier = EThermalShelterTier::OpenWilderness;
	DisplayedMeal = ECookedMealBuffType::None;
	DisplayedMealDuration = 0.0f;
}

void UAshenUserWidget_SanctuarySurvivalHUD::UpdateSurvivalHUD(
	float BodyTempC,
	EThermalShelterTier ShelterTier,
	ECookedMealBuffType ActiveMeal,
	float MealDurationRemaining)
{
	DisplayedBodyTempC = BodyTempC;
	DisplayedShelterTier = ShelterTier;
	DisplayedMeal = ActiveMeal;
	DisplayedMealDuration = MealDurationRemaining;
}
