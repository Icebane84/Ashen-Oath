// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCampfireCookingTypes.generated.h"

/**
 * ECampfireRecipeType
 * 
 * Recipes concocted at campfire cauldrons.
 */
UENUM(BlueprintType)
enum class ECampfireRecipeType : uint8
{
	None                    UMETA(DisplayName = "None"),
	SentinelsIronBroth      UMETA(DisplayName = "Sentinel's Iron Broth (+25% Poise, +150 Stamina)"),
	WhiteFlameHerbalTisane  UMETA(DisplayName = "White Flame Herbal Tisane (-30% Burnout Accumulation)"),
	GloomwoodVenisonStew    UMETA(DisplayName = "Gloomwood Venison Stew (+20% Kinetic Damage, Debt Freeze)"),
	GrandZenithSoulGoulash  UMETA(DisplayName = "Grand Zenith Soul-Ember Goulash (+25% All Stats, Sanity Max)")
};

/**
 * EIngredientQualityTier
 * 
 * Freshness and potency tier of culinary and alchemical ingredients.
 */
UENUM(BlueprintType)
enum class EIngredientQualityTier : uint8
{
	CommonForaged    UMETA(DisplayName = "Common Foraged (1.0x Potency)"),
	PreservedSalted  UMETA(DisplayName = "Preserved Salted (3.0x Shelf-Life)"),
	PristineEmber    UMETA(DisplayName = "Pristine Ember-Touched (1.5x Potency, +50% Buff Duration)"),
	SpoiledDebris    UMETA(DisplayName = "Spoiled Debris (Toxic, Inedible)")
};

/**
 * ECookingPotState
 * 
 * Lifecycle of the campfire cooking pot.
 */
UENUM(BlueprintType)
enum class ECookingPotState : uint8
{
	EmptyCold       UMETA(DisplayName = "Empty Cold (No Fire)"),
	SimmeringBoil   UMETA(DisplayName = "Simmering Boil (60-90°C, Adding Ingredients)"),
	ActiveStirring  UMETA(DisplayName = "Active Stirring (90-110°C, Stirring Rhythm)"),
	MealReadyServed UMETA(DisplayName = "Meal Ready Served (Freshly Cooked, Ready to Consume)"),
	BurntResidue    UMETA(DisplayName = "Burnt Residue (Overcooked / Ruined)")
};

/**
 * FCampfireStewStateVector
 * 
 * Real-time temperature and readiness telemetry of the campfire pot.
 */
USTRUCT(BlueprintType)
struct FCampfireStewStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	float TemperatureCelsius = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	float CookingProgress01 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	float StirringRhythmBonus = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	ECampfireRecipeType CurrentRecipe = ECampfireRecipeType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	ECookingPotState PotState = ECookingPotState::EmptyCold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	int32 PortionsRemaining = 0;
};

/**
 * FIngredientRationEntry
 * 
 * Tracked inventory ration with freshness decay.
 */
USTRUCT(BlueprintType)
struct FIngredientRationEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	FString IngredientName = TEXT("Wild Gloomroot");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	float FreshnessPercent = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	EIngredientQualityTier QualityTier = EIngredientQualityTier::CommonForaged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Cooking")
	int32 Quantity = 1;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCookingStateChanged, ECookingPotState, NewState, float, Temperature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMealPrepared, ECampfireRecipeType, Recipe, int32, PortionsCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMealConsumed, ECampfireRecipeType, RecipeConsumed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRationSpoiled, const FString&, IngredientName, int32, QuantityLost);
