// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEnvironmentalWeatherSubsystem.h"
#include "AshenDynamicWeatherAudioSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherAudioUpdatedSignature, EAshenWeatherState, NewWeatherState, float, AmbientWindVolume);

/**
 * UAshenDynamicWeatherAudioSubsystem
 *
 * World Subsystem modulating ambient blizzard winds, storm audio cues, and cavern echo volume based on EAshenWeatherState.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicWeatherAudioSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeatherAudio")
	void UpdateWeatherAudio(EAshenWeatherState WeatherState);

	UFUNCTION(BlueprintPure, Category = "AshenOath|WeatherAudio")
	float GetWindVolume() const { return CurrentWindVolume; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeatherAudio|Events")
	FOnWeatherAudioUpdatedSignature OnWeatherAudioUpdated;

private:
	float CurrentWindVolume = 0.2f;
	EAshenWeatherState ActiveState = EAshenWeatherState::ClearCalm;
};
