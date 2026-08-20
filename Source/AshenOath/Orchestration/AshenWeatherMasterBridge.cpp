// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Orchestration/AshenWeatherMasterBridge.h"

UAshenWeatherMasterBridge::UAshenWeatherMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWeatherMasterBridge::BeginPlay()
{
	Super::BeginPlay();
	bWeatherBridgeActive = true;
}

void UAshenWeatherMasterBridge::BroadcastWeatherChanged(EWeatherState NewWeather, float Toxicity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherMasterBridge: Broadcasted Weather Changed Event (Weather: %d, Toxicity: %.2f)."),
		static_cast<int32>(NewWeather), Toxicity);
}

void UAshenWeatherMasterBridge::BroadcastSanctuaryWardEntered(FName WardID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherMasterBridge: Broadcasted Sanctuary Ward Entered (Ward: '%s')."), *WardID.ToString());
}
