// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenCampfireCookingSubsystem.h"

UAshenCampfireCookingSubsystem::UAshenCampfireCookingSubsystem()
{
	PotState.TemperatureCelsius = 20.0f;
	PotState.CookingProgress01 = 0.0f;
	PotState.StirringRhythmBonus = 1.0f;
	PotState.CurrentRecipe = ECampfireRecipeType::None;
	PotState.PotState = ECookingPotState::EmptyCold;
	PotState.PortionsRemaining = 0;
}

bool UAshenCampfireCookingSubsystem::BeginCookingRecipe(ECampfireRecipeType Recipe)
{
	if (Recipe == ECampfireRecipeType::None)
	{
		return false;
	}

	PotState.CurrentRecipe = Recipe;
	PotState.TemperatureCelsius = 75.0f;
	PotState.CookingProgress01 = 0.10f;
	PotState.PotState = ECookingPotState::SimmeringBoil;
	PotState.PortionsRemaining = 0;

	OnCookingStateChanged.Broadcast(PotState.PotState, PotState.TemperatureCelsius);
	return true;
}

void UAshenCampfireCookingSubsystem::ApplyStirringInput(float RhythmAccuracy01)
{
	if (PotState.PotState != ECookingPotState::SimmeringBoil && PotState.PotState != ECookingPotState::ActiveStirring)
	{
		return;
	}

	PotState.PotState = ECookingPotState::ActiveStirring;
	const float Acc = FMath::Clamp(RhythmAccuracy01, 0.0f, 1.0f);
	PotState.StirringRhythmBonus = 1.0f + (Acc * 0.50f);
	PotState.CookingProgress01 = FMath::Clamp(PotState.CookingProgress01 + (0.25f * PotState.StirringRhythmBonus), 0.0f, 1.0f);
	PotState.TemperatureCelsius = FMath::Clamp(PotState.TemperatureCelsius + 5.0f, 60.0f, 110.0f);

	if (PotState.CookingProgress01 >= 1.0f)
	{
		PotState.PotState = ECookingPotState::MealReadyServed;
		PotState.PortionsRemaining = 3; // 1 portion for each trio member
		OnMealPrepared.Broadcast(PotState.CurrentRecipe, PotState.PortionsRemaining);
	}

	OnCookingStateChanged.Broadcast(PotState.PotState, PotState.TemperatureCelsius);
}

bool UAshenCampfireCookingSubsystem::ConsumeMealPortion()
{
	if (PotState.PotState != ECookingPotState::MealReadyServed || PotState.PortionsRemaining <= 0)
	{
		return false;
	}

	PotState.PortionsRemaining--;
	OnMealConsumed.Broadcast(PotState.CurrentRecipe);

	if (PotState.PortionsRemaining <= 0)
	{
		PotState.PotState = ECookingPotState::EmptyCold;
		PotState.CurrentRecipe = ECampfireRecipeType::None;
		PotState.CookingProgress01 = 0.0f;
		PotState.TemperatureCelsius = 25.0f;
		OnCookingStateChanged.Broadcast(PotState.PotState, PotState.TemperatureCelsius);
	}

	return true;
}
