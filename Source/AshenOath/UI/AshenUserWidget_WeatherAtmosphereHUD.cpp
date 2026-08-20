// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_WeatherAtmosphereHUD.h"

void UAshenUserWidget_WeatherAtmosphereHUD::UpdateAtmosphereHUD(EWeatherState InWeather, float InToxicity, float InFilterHealth)
{
	DisplayedWeather = InWeather;
	ToxicityPercent = FMath::Clamp(InToxicity * 100.0f, 0.0f, 100.0f);
	FilterHealthPercent = FMath::Clamp(InFilterHealth * 100.0f, 0.0f, 100.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_WeatherAtmosphereHUD: Weather HUD -> Weather: %d, Toxicity: %.1f%%, Filter: %.1f%%"),
		static_cast<int32>(DisplayedWeather), ToxicityPercent, FilterHealthPercent);
}
