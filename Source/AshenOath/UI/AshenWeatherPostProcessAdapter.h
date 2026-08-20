// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenWeatherAtmosphereTypes.h"
#include "AshenWeatherPostProcessAdapter.generated.h"

/**
 * UAshenWeatherPostProcessAdapter
 * Manages post-process weather shaders: volumetric ash fog, rain streaks, miasma chromatic distortion, and blizzard frost vignetting.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeatherPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeatherPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyWeatherVisualEffects(EWeatherState Weather, float Toxicity, float WindStrength);
};
