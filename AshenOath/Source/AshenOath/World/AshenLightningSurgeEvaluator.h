// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenLightningSurgeEvaluator.generated.h"

/**
 * UAshenLightningSurgeEvaluator
 * 
 * Computes atmospheric ionization buildup, telegraph warning duration (1.5s), and lethal lightning shock damage (850 Dmg).
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLightningSurgeEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenLightningSurgeEvaluator();

	/** Evaluates lightning strike damage based on atmospheric severity */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Lightning")
	float EvaluateLightningStrikeDamage(EAtmosphericSeverity Severity) const;

	/** Gets telegraph warning duration before strike impact */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Lightning")
	float GetTelegraphWarningDurationSeconds() const { return 1.5f; }

	/** Gets telegraph warning radius in Unreal Units */
	UFUNCTION(BlueprintPure, Category = "Ashen|Weather|Lightning")
	float GetTelegraphRadiusUU() const { return 250.0f; }
};
