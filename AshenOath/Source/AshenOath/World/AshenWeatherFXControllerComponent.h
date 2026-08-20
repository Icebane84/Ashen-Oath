// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnvironmentalWeatherSubsystem.h"
#include "AshenWeatherFXControllerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherFXUpdatedSignature, EAshenWeatherState, NewWeather, float, Intensity);

/**
 * UAshenWeatherFXControllerComponent
 *
 * Listens to weather state transitions from UAshenEnvironmentalWeatherSubsystem
 * and dynamically adjusts atmospheric fog density, particle multipliers, and wind audio parameters.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherFXControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherFXControllerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeatherFX")
	void ApplyWeatherFX(EAshenWeatherState WeatherType, float Intensity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|WeatherFX")
	EAshenWeatherState GetCurrentWeatherType() const { return CurrentWeather; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|WeatherFX")
	float GetCurrentIntensity() const { return CurrentIntensity; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeatherFX|Events")
	FOnWeatherFXUpdatedSignature OnWeatherFXUpdated;

private:
	EAshenWeatherState CurrentWeather = EAshenWeatherState::ClearCalm;
	float CurrentIntensity = 0.0f;
};
