// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSanctuarySurvivalTypes.generated.h"

/**
 * ECookedMealBuffType
 * 
 * Campfire cooked meals providing biological hazard immunities.
 */
UENUM(BlueprintType)
enum class ECookedMealBuffType : uint8
{
	None                   UMETA(DisplayName = "None (No Meal Active)"),
	GlacialHeartStew       UMETA(DisplayName = "Glacial Heart Stew (100% Frostbite & Blizzard Immunity)"),
	VitriolPurgeBroth      UMETA(DisplayName = "Vitriol Purge Broth (100% Acid Rain Corrosion Immunity)"),
	CinderAshCake          UMETA(DisplayName = "Cinder Ash Cake (100% Ash Storm Inhalation Resistance)"),
	SmokedTravelingRations UMETA(DisplayName = "Smoked Traveling Rations (Stamina Capacity Decay Immunity)")
};

/**
 * EThermalShelterTier
 * 
 * Environmental thermodynamic shelter levels.
 */
UENUM(BlueprintType)
enum class EThermalShelterTier : uint8
{
	OpenWilderness         UMETA(DisplayName = "Open Wilderness (100% Weather Decay, Hypothermia Risk)"),
	NaturalCavern          UMETA(DisplayName = "Natural Cavern (75% Windbreak, 2x Cooking Speed)"),
	SanctuaryHearthRadius  UMETA(DisplayName = "Sanctuary Hearth (100% Haven, 37.0C Body Temp, 0 Sanity Decay)")
};

/**
 * ESurvivalJournalCategory
 * 
 * Forensic journal classification for sanctuary discoveries.
 */
UENUM(BlueprintType)
enum class ESurvivalJournalCategory : uint8
{
	BeaconLoreSketch       UMETA(DisplayName = "Ancient Beacon Lore Sketch"),
	RegionalHazardAnalysis UMETA(DisplayName = "Regional Weather Hazard Analysis"),
	BotanicalForagingNotes UMETA(DisplayName = "Botanical Foraging Notes")
};

/**
 * FMealHazardImmunityData
 * 
 * Active biological meal buffs and remaining durations.
 */
USTRUCT(BlueprintType)
struct FMealHazardImmunityData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	ECookedMealBuffType ActiveMeal = ECookedMealBuffType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	float RemainingDurationSeconds = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	float HazardImmunityPercent = 0.0f;
};

/**
 * FShelterThermodynamicState
 * 
 * Thermodynamic parameters of the current location.
 */
USTRUCT(BlueprintType)
struct FShelterThermodynamicState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	EThermalShelterTier ShelterTier = EThermalShelterTier::OpenWilderness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	float BodyTemperatureCelsius = 37.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	float WeatherDecayMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	float CookingRateMultiplier = 1.0f;
};

/**
 * FSanctuaryBeaconRecord
 * 
 * Metadata for a discovered sanctuary beacon.
 */
USTRUCT(BlueprintType)
struct FSanctuaryBeaconRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	FName BeaconId = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	FString RegionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	bool bIsIgnited = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	float HavenRadiusUU = 1200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Survival")
	FText InscribedJournalEntry;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMealBuffApplied, ECookedMealBuffType, MealType, float, DurationSeconds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShelterTierChanged, EThermalShelterTier, NewTier, const FShelterThermodynamicState&, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanctuaryBeaconIgnited, FName, BeaconId, const FSanctuaryBeaconRecord&, Record);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnForensicJournalEntryAutoLogged, ESurvivalJournalCategory, Category, FText, EntryText);
