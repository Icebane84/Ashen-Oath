// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherSaveGameAdapter.generated.h"

/**
 * UAshenWeatherSaveGameAdapter
 * Serializes active weather state, total exposure times in toxic zones, and discovered atmospheric sanctuary wards.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeatherSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveWeatherState(EWeatherState ActiveWeather, int32 DiscoveredWardsCount);
};
