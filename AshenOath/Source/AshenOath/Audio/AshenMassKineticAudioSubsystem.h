// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenMassKineticAudioSubsystem.generated.h"

/**
 * UAshenMassKineticAudioSubsystem
 * 
 * Modulates MetaSounds audio synthesis:
 * - Blade whoosh pitch down-tunes proportionally with mass and velocity
 * - Heavy bass impact sub-oscillators scale with kinetic energy (Joules)
 */
UCLASS()
class ASHENOATH_API UAshenMassKineticAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenMassKineticAudioSubsystem();

	/** Calculates pitch scale for blade whoosh */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Kinetic")
	float CalculateWhooshPitch(float WeaponMassKG, float TipVelocity) const;

	/** Calculates bass sub-boost for impact */
	UFUNCTION(BlueprintPure, Category = "Ashen|Audio|Kinetic")
	float CalculateImpactBassBoost(float EnergyJoules) const;
};
