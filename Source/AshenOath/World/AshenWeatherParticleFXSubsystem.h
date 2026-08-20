// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenWeatherParticleFXSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeatherParticleFXSpawnedSignature, FName, WeatherTypeTag, float, ParticleDensity);

/**
 * UAshenWeatherParticleFXSubsystem
 *
 * World Subsystem spawning weather particles (rain, ash storm, fog).
 */
UCLASS()
class ASHENOATH_API UAshenWeatherParticleFXSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeatherParticles")
	void SpawnWeatherParticleFX(FName WeatherTypeTag, float Density = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeatherParticles|Events")
	FOnWeatherParticleFXSpawnedSignature OnWeatherParticleFXSpawned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeatherParticles")
	FName CurrentActiveWeatherTag;
};
