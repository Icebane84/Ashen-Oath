// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenUserWidget_WeatherHazardHUD.generated.h"

/**
 * UAshenUserWidget_WeatherHazardHUD
 * 
 * UMG widget displaying real-time ambient temperature, acid corrosion rates, lightning charge telemetry, and shelter status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WeatherHazardHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_WeatherHazardHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed atmospheric telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Weather")
	void UpdateWeatherHUD(const FWeatherAtmosphericVector& Atmosphere, EWeatherShelterType Shelter);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Weather")
	FWeatherAtmosphericVector DisplayedAtmosphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Weather")
	EWeatherShelterType DisplayedShelter = EWeatherShelterType::ExposedWilds;
};
