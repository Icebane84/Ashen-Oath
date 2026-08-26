// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCampfireCookingHapticBridge.h"

UAshenCampfireCookingHapticBridge::UAshenCampfireCookingHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCampfireCookingHapticBridge::EvaluateCookingHaptics(
	ECookingPotState PotState,
	float TemperatureCelsius,
	float& OutStirringResistance,
	float& OutWarmthCrackleGain,
	float& OutMealServedChime)
{
	// Viscosity stirring resistance
	OutStirringResistance = (PotState == ECookingPotState::ActiveStirring) ? 0.45f : 0.10f;

	// Warm ember crackle
	OutWarmthCrackleGain = (PotState != ECookingPotState::EmptyCold) ? 0.65f : 0.15f;

	// Meal served chime
	OutMealServedChime = (PotState == ECookingPotState::MealReadyServed) ? 1.00f : 0.0f;
}
