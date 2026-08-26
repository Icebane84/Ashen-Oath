// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenWeatherSaveGameAdapter.generated.h"

/**
 * UAshenWeatherSaveGameAdapter
 * 
 * Serializes active weather hazard state, atmospheric temperature, and prevailing storm intensity into persistent save files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeatherSaveGameAdapter();

	/** Packages weather state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageWeatherState(EWeatherHazardState WeatherState, EAtmosphericSeverity Severity, float Temperature);

	/** Restores weather state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreWeatherState(EWeatherHazardState& OutWeatherState, EAtmosphericSeverity& OutSeverity, float& OutTemperature);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EWeatherHazardState SavedWeatherState = EWeatherHazardState::ClearTemperate;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EAtmosphericSeverity SavedSeverity = EAtmosphericSeverity::MildDrift;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedTemperature = 18.0f;

private:
	bool bHasSavedData = false;
};
