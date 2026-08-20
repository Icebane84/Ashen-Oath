// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEnvironmentalWeatherSubsystem.h"
#include "AshenDynamicWeatherVFXSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherVFXUpdatedSignature, EAshenWeatherState, WeatherState, float, FogDensityMultiplier);

/**
 * UAshenDynamicWeatherVFXSubsystem
 *
 * World Subsystem managing volumetric fog density, ash blizzard particle density, and ambient lighting based on weather state.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicWeatherVFXSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeatherVFX")
	void ModulateVFXForWeatherState(EAshenWeatherState WeatherState);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeatherVFX|Events")
	FOnWeatherVFXUpdatedSignature OnWeatherVFXUpdated;
};
