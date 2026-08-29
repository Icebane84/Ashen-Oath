// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenAlchemicalSlagTypes.generated.h"

/**
 * EOathbringerBladeSurfaceState
 * 
 * Physical/thermal patina state of the Oathbringer Greatsword.
 */
UENUM(BlueprintType)
enum class EOathbringerBladeSurfaceState : uint8
{
	PolishedResolve       UMETA(DisplayName = "Polished Resolve (0.0-0.20 Soot: +15% Parry Window, Gold Runes)"),
	AccumulatingSoot      UMETA(DisplayName = "Accumulating Soot (0.21-0.79 Soot: Charred Nightsteel)"),
	SuperheatedThermalSlag UMETA(DisplayName = "Superheated Thermal Slag (>=0.80 Soot: +35 Heat Dmg, Slag Burst Ready)")
};

/**
 * EAlchemicalBladeCoating
 * 
 * Garrett's craftable alchemical weapon coatings.
 */
UENUM(BlueprintType)
enum class EAlchemicalBladeCoating : uint8
{
	None                  UMETA(DisplayName = "None (Uncoated Steel)"),
	PyrophoricNaphtha     UMETA(DisplayName = "Pyrophoric Naphtha (+25 Fire Dmg, Slag Conflagration)"),
	GlacialFrostResin     UMETA(DisplayName = "Glacial Frost Resin (-30% Speed, Thermal Shock Shatter)"),
	VitriolAcid           UMETA(DisplayName = "Vitriol Acid (-35% Enemy Armor, Acidic Vapor Cloud)"),
	ConductiveCopperSalve UMETA(DisplayName = "Conductive Copper Salve (+100% Arc Range, Galvanic Pull)")
};

/**
 * EThermalReactionType
 * 
 * Chemical/thermal reaction combinations triggered on hit.
 */
UENUM(BlueprintType)
enum class EThermalReactionType : uint8
{
	None                      UMETA(DisplayName = "Standard Hit"),
	ConflagrationDeflagration UMETA(DisplayName = "Conflagration (450 Heat AoE Firestorm)"),
	ThermalShockShatter       UMETA(DisplayName = "Thermal Shock (+100% Poise Shatter & Armor Break)"),
	GalvanicShockBurst        UMETA(DisplayName = "Galvanic Pull (+500 Shock Dmg & Lightning Arc)"),
	AcidicVaporCloud          UMETA(DisplayName = "Acidic Vapor (300uu Corrosive Blind Smoke)")
};

/**
 * FBladeSootCoatingVector
 * 
 * Live surface parameters of Oathbringer.
 */
USTRUCT(BlueprintType)
struct FBladeSootCoatingVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	float SootLevel = 0.0f; // 0.0 to 1.0

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	EOathbringerBladeSurfaceState SurfaceState = EOathbringerBladeSurfaceState::PolishedResolve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	EAlchemicalBladeCoating ActiveCoating = EAlchemicalBladeCoating::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	int32 RemainingCoatingCharges = 0;
};

/**
 * FThermalReactionResult
 * 
 * Output metrics from a chemical/thermal reaction.
 */
USTRUCT(BlueprintType)
struct FThermalReactionResult
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	EThermalReactionType ReactionType = EThermalReactionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	float BonusDamage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	float AoERadiusUU = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|AlchemicalSlag")
	float PoiseDamageMultiplier = 1.0f;
};

// Multicast Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBladeSootLevelChanged, float, NewSootLevel, EOathbringerBladeSurfaceState, SurfaceState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAlchemicalCoatingApplied, EAlchemicalBladeCoating, Coating, int32, Charges);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnThermalReactionTriggered, EThermalReactionType, Reaction, const FThermalReactionResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBladePolishedAtCampfire, float, ResolveBuffDurationSeconds);
