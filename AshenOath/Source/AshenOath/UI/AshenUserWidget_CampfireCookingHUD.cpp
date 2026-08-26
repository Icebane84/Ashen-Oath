// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenUserWidget_CampfireCookingHUD.h"

UAshenUserWidget_CampfireCookingHUD::UAshenUserWidget_CampfireCookingHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayedPotState.TemperatureCelsius = 20.0f;
	DisplayedPotState.CookingProgress01 = 0.0f;
	DisplayedPotState.StirringRhythmBonus = 1.0f;
	DisplayedPotState.CurrentRecipe = ECampfireRecipeType::None;
	DisplayedPotState.PotState = ECookingPotState::EmptyCold;
	DisplayedPotState.PortionsRemaining = 0;
}

void UAshenUserWidget_CampfireCookingHUD::UpdateCookingHUD(const FCampfireStewStateVector& State)
{
	DisplayedPotState = State;
}
