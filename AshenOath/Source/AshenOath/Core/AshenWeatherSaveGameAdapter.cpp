// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenWeatherSaveGameAdapter.h"

UAshenWeatherSaveGameAdapter::UAshenWeatherSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeatherSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenWeatherSaveGameAdapter::SaveWeatherState(EWeatherState ActiveWeather, int32 DiscoveredWardsCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherSaveGameAdapter: Saved Weather State (Weather: %d, Wards: %d) to SaveGame."),
		static_cast<int32>(ActiveWeather), DiscoveredWardsCount);
	return true;
}
