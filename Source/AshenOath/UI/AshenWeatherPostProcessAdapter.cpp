// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenWeatherPostProcessAdapter.h"

UAshenWeatherPostProcessAdapter::UAshenWeatherPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeatherPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWeatherPostProcessAdapter::ApplyWeatherVisualEffects(EWeatherState Weather, float Toxicity, float WindStrength)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherPostProcessAdapter: Applied Weather Post-Process -> Weather: %d, Toxicity: %.2f, Wind: %.2f"),
		static_cast<int32>(Weather), Toxicity, WindStrength);
}
