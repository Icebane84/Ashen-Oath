// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherMasterBridge.generated.h"

/**
 * UAshenWeatherMasterBridge
 * Master domain bridge broadcasting weather state changes, miasma hazard pulses, and sanctuary ward entries across subsystems.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeatherMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bWeatherBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastWeatherChanged(EWeatherState NewWeather, float Toxicity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastSanctuaryWardEntered(FName WardID);
};
