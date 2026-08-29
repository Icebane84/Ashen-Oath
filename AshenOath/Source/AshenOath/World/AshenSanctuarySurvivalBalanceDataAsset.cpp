// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSanctuarySurvivalBalanceDataAsset.h"

FShelterThermodynamicBalancing UAshenSanctuarySurvivalBalanceDataAsset::GetClampedShelterBalancing() const
{
	FShelterThermodynamicBalancing Clamped = ShelterBalancing;
	Clamped.WildernessHypothermiaHPLoss = FMath::Clamp(Clamped.WildernessHypothermiaHPLoss, -10.0f, 0.0f);
	Clamped.CavernCookingSpeedMultiplier = FMath::Clamp(Clamped.CavernCookingSpeedMultiplier, 1.0f, 5.0f);
	Clamped.HearthHealthRegenPerSecond = FMath::Clamp(Clamped.HearthHealthRegenPerSecond, 0.0f, 20.0f);
	Clamped.CavernWindbreakReduction = FMath::Clamp(Clamped.CavernWindbreakReduction, 0.0f, 1.0f);
	return Clamped;
}

FSurvivalMealBalancing UAshenSanctuarySurvivalBalanceDataAsset::GetClampedMealBalancing() const
{
	FSurvivalMealBalancing Clamped = MealBalancing;
	Clamped.DefaultMealDurationSeconds = FMath::Clamp(Clamped.DefaultMealDurationSeconds, 60.0f, 3600.0f);
	Clamped.MatchedHazardDamageReduction = FMath::Clamp(Clamped.MatchedHazardDamageReduction, 0.50f, 1.0f);
	return Clamped;
}

FSanctuaryBeaconBalancing UAshenSanctuarySurvivalBalanceDataAsset::GetClampedBeaconBalancing() const
{
	FSanctuaryBeaconBalancing Clamped = BeaconBalancing;
	Clamped.BeaconHavenRadiusUU = FMath::Clamp(Clamped.BeaconHavenRadiusUU, 300.0f, 5000.0f);
	return Clamped;
}
