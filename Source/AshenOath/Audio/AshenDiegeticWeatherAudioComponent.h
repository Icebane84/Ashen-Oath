// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenDiegeticWeatherAudioComponent.generated.h"

/**
 * UAshenDiegeticWeatherAudioComponent
 * Manages spatial weather soundscapes: howling ash blizzards, resonant lightning claps, and breathing respirator audio.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticWeatherAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticWeatherAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateWeatherAudio(EWeatherState Weather, float WindIntensity, float FilterIntegrity);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayLightningStrikeCue();
};
