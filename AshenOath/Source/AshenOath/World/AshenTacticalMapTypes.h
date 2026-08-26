// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenTacticalMapTypes.generated.h"

/**
 * EWaypointBeaconState
 * 
 * Discovery and attunement status of sanctuary campfire waypoints.
 */
UENUM(BlueprintType)
enum class EWaypointBeaconState : uint8
{
	UndiscoveredShadow UMETA(DisplayName = "Undiscovered Shadow (Hidden in Fog)"),
	DiscoveredBeacon   UMETA(DisplayName = "Discovered Beacon (Visible on Map)"),
	AttunedSanctuary   UMETA(DisplayName = "Attuned Sanctuary (Fast Travel Enabled)"),
	ContestedCorrupted UMETA(DisplayName = "Contested Corrupted (Blocked by Enemies)")
};

/**
 * ETravelHazardType
 * 
 * Roadside hazards encountered during overland travel.
 */
UENUM(BlueprintType)
enum class ETravelHazardType : uint8
{
	None             UMETA(DisplayName = "None (Safe Passage)"),
	RoadsideAmbush   UMETA(DisplayName = "Roadside Ambush (Hostile Skirmish)"),
	BlizzardCollapse UMETA(DisplayName = "Blizzard Collapse (Thermal Hazard)"),
	CorruptedMiasma  UMETA(DisplayName = "Corrupted Miasma (Soul Debt Surge)")
};

/**
 * EMapRegionBiome
 * 
 * Biomes across the sundered landscape.
 */
UENUM(BlueprintType)
enum class EMapRegionBiome : uint8
{
	GloomwoodForest    UMETA(DisplayName = "Gloomwood Forest"),
	FrostveinPeaks     UMETA(DisplayName = "Frostvein Peaks"),
	AshenCaldera       UMETA(DisplayName = "Ashen Caldera"),
	SearingCatacombs   UMETA(DisplayName = "Searing Catacombs"),
	FloatingArchipelago UMETA(DisplayName = "Floating Archipelago"),
	GrandZenithAltar   UMETA(DisplayName = "Grand Zenith Altar")
};

/**
 * FTacticalWaypointVector
 * 
 * Data vector representing a fast travel sanctuary waypoint.
 */
USTRUCT(BlueprintType)
struct FTacticalWaypointVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	FString WaypointId = TEXT("Waypoint_01");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	FText DisplayName = FText::FromString(TEXT("Gloomwood Sanctuary Hearth"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	FVector WorldLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	EWaypointBeaconState BeaconState = EWaypointBeaconState::UndiscoveredShadow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	EMapRegionBiome Biome = EMapRegionBiome::GloomwoodForest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	bool bIsHearthRestSite = true;
};

/**
 * FTravelHazardEncounterVector
 * 
 * Outcome vector of an overland travel hazard check.
 */
USTRUCT(BlueprintType)
struct FTravelHazardEncounterVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	ETravelHazardType HazardType = ETravelHazardType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	float AmbushProbabilityPercent = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	float TravelDistanceKilometers = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Map")
	bool bAmbushTriggered = false;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWaypointStateChanged, const FString&, WaypointId, EWaypointBeaconState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFastTravelInitiated, const FString&, SourceWaypointId, const FString&, DestinationWaypointId);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTravelHazardTriggered, const FTravelHazardEncounterVector&, HazardEncounter);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFogOfWarUnveiled, const FVector&, WorldLocation, float, UnveilRadiusUU);
