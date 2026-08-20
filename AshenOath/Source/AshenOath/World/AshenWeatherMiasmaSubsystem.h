// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherMiasmaSubsystem.generated.h"

/**
 * UAshenWeatherMiasmaSubsystem
 * GameInstance Subsystem managing dynamic world weather transitions (ClearEmber, AshBlizzard, VoidMiasma, PsychicStorm) and global toxicity.
 */
UCLASS()
class ASHENOATH_API UAshenWeatherMiasmaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weather")
	FWeatherAtmosphereData AtmosphereData;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	bool TransitionToWeather(EWeatherState NewWeather);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	EWeatherState GetCurrentWeather() const { return AtmosphereData.CurrentWeather; }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weather")
	float GetAtmosphericToxicity() const { return AtmosphereData.AtmosphericToxicity; }
};
