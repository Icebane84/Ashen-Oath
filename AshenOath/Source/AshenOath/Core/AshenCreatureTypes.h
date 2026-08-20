// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenCreatureTypes.generated.h"

/**
 * Creature Archetype classification for Shattered Lands entities.
 */
UENUM(BlueprintType)
enum class ECreatureArchetype : uint8
{
	Custom            UMETA(DisplayName = "Custom"),
	BlightGhoul       UMETA(DisplayName = "Blight Ghoul (Skirmisher)"),
	AshenAbomination  UMETA(DisplayName = "Ashen Abomination (Brute)"),
	AetherWeaver      UMETA(DisplayName = "Aether-Weaver (Alien Predation)"),
	GeodeLurker       UMETA(DisplayName = "Geode-Lurker (Perverted Symbiosis)")
};

/**
 * Structural definition for creature material and phase transition settings.
 */
USTRUCT(BlueprintType)
struct FAshenCreatureData
{
	GENERATED_BODY()

	/** Archetype classification of this creature */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature")
	ECreatureArchetype Archetype = ECreatureArchetype::Custom;

	/** Primary pulse rate for emissive core or crystal masks */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature", meta = (ClampMin = "0.0"))
	float EmissivePulseRate = 1.0f;

	/** Intensity multiplier for glowing fracture lines or cores */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature", meta = (ClampMin = "0.0"))
	float EmissiveIntensity = 5.0f;

	/** Phase transition health percentage threshold (0.0 to 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float PhaseTransitionThreshold = 0.5f;
};
