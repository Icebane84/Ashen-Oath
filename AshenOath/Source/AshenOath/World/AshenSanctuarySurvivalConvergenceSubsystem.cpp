// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenSanctuarySurvivalConvergenceSubsystem.h"

UAshenSanctuarySurvivalConvergenceSubsystem::UAshenSanctuarySurvivalConvergenceSubsystem()
{
	ActiveMealData.ActiveMeal = ECookedMealBuffType::None;
	ActiveMealData.RemainingDurationSeconds = 0.0f;
	ActiveMealData.HazardImmunityPercent = 0.0f;

	CurrentThermodynamics.ShelterTier = EThermalShelterTier::OpenWilderness;
	CurrentThermodynamics.BodyTemperatureCelsius = 37.0f;
	CurrentThermodynamics.WeatherDecayMultiplier = 1.0f;
	CurrentThermodynamics.CookingRateMultiplier = 1.0f;
}

void UAshenSanctuarySurvivalConvergenceSubsystem::ApplyMealBuff(
	ECookedMealBuffType MealType,
	float DurationSeconds)
{
	ActiveMealData.ActiveMeal = MealType;
	ActiveMealData.RemainingDurationSeconds = DurationSeconds;
	ActiveMealData.HazardImmunityPercent = 1.00f; // 100% Immunity

	OnMealBuffApplied.Broadcast(MealType, DurationSeconds);
}

void UAshenSanctuarySurvivalConvergenceSubsystem::SetShelterTier(
	EThermalShelterTier NewTier)
{
	if (CurrentThermodynamics.ShelterTier != NewTier)
	{
		CurrentThermodynamics.ShelterTier = NewTier;
		UpdateThermodynamicState();
		OnShelterTierChanged.Broadcast(NewTier, CurrentThermodynamics);
	}
}

void UAshenSanctuarySurvivalConvergenceSubsystem::IgniteBeacon(
	FName BeaconId,
	const FString& RegionName,
	const FText& InscribedLore)
{
	FSanctuaryBeaconRecord Record;
	Record.BeaconId = BeaconId;
	Record.RegionName = RegionName;
	Record.bIsIgnited = true;
	Record.HavenRadiusUU = 1200.0f;
	Record.InscribedJournalEntry = InscribedLore;

	DiscoveredBeacons.Add(BeaconId, Record);

	SetShelterTier(EThermalShelterTier::SanctuaryHearthRadius);

	OnSanctuaryBeaconIgnited.Broadcast(BeaconId, Record);
	OnForensicJournalEntryAutoLogged.Broadcast(ESurvivalJournalCategory::BeaconLoreSketch, InscribedLore);
}

bool UAshenSanctuarySurvivalConvergenceSubsystem::IsBeaconIgnited(
	FName BeaconId) const
{
	if (const FSanctuaryBeaconRecord* Record = DiscoveredBeacons.Find(BeaconId))
	{
		return Record->bIsIgnited;
	}
	return false;
}

void UAshenSanctuarySurvivalConvergenceSubsystem::UpdateThermodynamicState()
{
	switch (CurrentThermodynamics.ShelterTier)
	{
	case EThermalShelterTier::SanctuaryHearthRadius:
		CurrentThermodynamics.BodyTemperatureCelsius = 37.0f;
		CurrentThermodynamics.WeatherDecayMultiplier = 0.0f;
		CurrentThermodynamics.CookingRateMultiplier = 2.0f;
		break;

	case EThermalShelterTier::NaturalCavern:
		CurrentThermodynamics.WeatherDecayMultiplier = 0.25f; // 75% block
		CurrentThermodynamics.CookingRateMultiplier = 2.0f;   // 50% faster cooking
		break;

	case EThermalShelterTier::OpenWilderness:
	default:
		CurrentThermodynamics.WeatherDecayMultiplier = 1.0f;
		CurrentThermodynamics.CookingRateMultiplier = 1.0f;
		break;
	}
}
