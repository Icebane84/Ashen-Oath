// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenUserWidget_WeatherAtmosphereHUD.generated.h"

/**
 * UAshenUserWidget_WeatherAtmosphereHUD
 * Somatic UI widget displaying active weather conditions, atmospheric toxicity meters, and respirator filter health.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WeatherAtmosphereHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EWeatherState DisplayedWeather = EWeatherState::ClearEmber;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ToxicityPercent = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float FilterHealthPercent = 100.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateAtmosphereHUD(EWeatherState InWeather, float InToxicity, float InFilterHealth);
};
