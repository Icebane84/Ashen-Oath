// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenSanctuarySurvivalConvergenceSubsystem.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenSanctuarySurvivalConvergenceSubsystem::UAshenSanctuarySurvivalConvergenceSubsystem()
{
	ActiveMealData.ActiveMeal = ECookedMealBuffType::None;
	ActiveMealData.RemainingDurationSeconds = 0.0f;
	ActiveMealData.HazardImmunityPercent = 0.0f;

	CurrentThermodynamics.ShelterTier = EThermalShelterTier::OpenWilderness;
	CurrentThermodynamics.BodyTemperatureCelsius = 37.0f;
	CurrentThermodynamics.WeatherDecayMultiplier = 1.0f;
	CurrentThermodynamics.CookingRateMultiplier = 1.0f;

	BalanceDataAsset = nullptr;
}

void UAshenSanctuarySurvivalConvergenceSubsystem::ApplyMealBuff(
	ECookedMealBuffType MealType,
	float DurationSeconds)
{
	ActiveMealData.ActiveMeal = MealType;
	ActiveMealData.RemainingDurationSeconds = DurationSeconds;
	ActiveMealData.HazardImmunityPercent = 1.0f;

	if (OnMealBuffApplied.IsBound())
	{
		OnMealBuffApplied.Broadcast(MealType, DurationSeconds);
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuarySurvivalConvergenceSubsystem: Meal Buff %d applied for %.1fs (100%% Hazard Immunity)."),
		(int32)MealType, DurationSeconds);
}

void UAshenSanctuarySurvivalConvergenceSubsystem::SetShelterTier(EThermalShelterTier NewTier)
{
	CurrentThermodynamics.ShelterTier = NewTier;

	switch (NewTier)
	{
	case EThermalShelterTier::NaturalCavern:
		CurrentThermodynamics.WeatherDecayMultiplier = 0.25f;
		CurrentThermodynamics.CookingRateMultiplier = 2.0f;
		CurrentThermodynamics.BodyTemperatureCelsius = 37.0f;
		break;

	case EThermalShelterTier::SanctuaryHearthRadius:
		CurrentThermodynamics.WeatherDecayMultiplier = 0.0f;
		CurrentThermodynamics.CookingRateMultiplier = 2.0f;
		CurrentThermodynamics.BodyTemperatureCelsius = 37.0f;
		break;

	case EThermalShelterTier::OpenWilderness:
	default:
		CurrentThermodynamics.WeatherDecayMultiplier = 1.0f;
		CurrentThermodynamics.CookingRateMultiplier = 1.0f;
		break;
	}

	if (OnShelterTierChanged.IsBound())
	{
		OnShelterTierChanged.Broadcast(NewTier, CurrentThermodynamics);
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuarySurvivalConvergenceSubsystem: Shelter Tier updated to %d (Decay Mult: %.2f, Cooking Mult: %.2f)."),
		(int32)NewTier, CurrentThermodynamics.WeatherDecayMultiplier, CurrentThermodynamics.CookingRateMultiplier);
}

void UAshenSanctuarySurvivalConvergenceSubsystem::IgniteBeacon(
	FName BeaconId,
	const FString& RegionName,
	const FText& InscribedLore)
{
	float HavenRadius = 1200.0f;
	if (BalanceDataAsset)
	{
		HavenRadius = BalanceDataAsset->GetClampedBeaconBalancing().BeaconHavenRadiusUU;
	}

	FSanctuaryBeaconRecord Record;
	Record.BeaconId = BeaconId;
	Record.RegionName = RegionName;
	Record.bIsIgnited = true;
	Record.HavenRadiusUU = HavenRadius;
	Record.InscribedJournalEntry = InscribedLore;

	DiscoveredBeacons.Add(BeaconId, Record);

	// Automatically transition to Sanctuary Tier
	SetShelterTier(EThermalShelterTier::SanctuaryHearthRadius);

	// 1. Purge Companion Fatigue on GameInstance
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenCompanionFatigueSubsystem* FatigueSubsystem = GI->GetSubsystem<UAshenCompanionFatigueSubsystem>())
			{
				FatigueSubsystem->ResetAllFatigue();
			}
		}
	}

	if (OnSanctuaryBeaconIgnited.IsBound())
	{
		OnSanctuaryBeaconIgnited.Broadcast(BeaconId, Record);
	}

	if (OnForensicJournalEntryAutoLogged.IsBound())
	{
		OnForensicJournalEntryAutoLogged.Broadcast(ESurvivalJournalCategory::BeaconLoreSketch, InscribedLore);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuarySurvivalConvergenceSubsystem: *** SANCTUARY BEACON [%s] IGNITED *** in %s (Haven Radius: %.1fuu, Fatigue Purged)!"),
		*BeaconId.ToString(), *RegionName, HavenRadius);
}

bool UAshenSanctuarySurvivalConvergenceSubsystem::IsBeaconIgnited(FName BeaconId) const
{
	if (const FSanctuaryBeaconRecord* Record = DiscoveredBeacons.Find(BeaconId))
	{
		return Record->bIsIgnited;
	}
	return false;
}
