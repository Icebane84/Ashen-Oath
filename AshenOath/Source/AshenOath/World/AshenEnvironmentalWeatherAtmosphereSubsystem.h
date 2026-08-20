// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEnvironmentalWeatherAtmosphereSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherAtmosphereModulatedSignature, float, StormDensityPercent, float, WindShearVelocity);

/**
 * UAshenEnvironmentalWeatherAtmosphereSubsystem
 *
 * World Subsystem modulating wind shear, storm density, and rain particle collision based on Regional Corruption.
 */
UCLASS()
class ASHENOATH_API UAshenEnvironmentalWeatherAtmosphereSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeatherAtmosphere")
	void ModulateWeatherForCorruption(float RegionalCorruptionPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeatherAtmosphere|Events")
	FOnWeatherAtmosphereModulatedSignature OnWeatherModulated;
};
