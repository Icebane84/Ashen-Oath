// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenWeatherAudioModulationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherAudioModulatedSignature, float, RainVolumeMultiplier, float, LowPassFilterCutoff);

/**
 * UAshenWeatherAudioModulationSubsystem
 *
 * World Subsystem modulating ambient wind/rain audio frequencies.
 */
UCLASS()
class ASHENOATH_API UAshenWeatherAudioModulationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeatherAudio")
	void ModulateWeatherAudio(float StormDensityPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeatherAudio|Events")
	FOnWeatherAudioModulatedSignature OnWeatherAudioModulated;
};
