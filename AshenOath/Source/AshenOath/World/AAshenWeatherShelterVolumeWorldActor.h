// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AAshenWeatherShelterVolumeWorldActor.generated.h"

/**
 * AAshenWeatherShelterVolumeWorldActor
 * 
 * Spatial trigger volume world actor representing cavern overhangs, ruined stone arches, and sanctuary brazier domes.
 */
UCLASS()
class ASHENOATH_API AAshenWeatherShelterVolumeWorldActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenWeatherShelterVolumeWorldActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Weather")
	EWeatherShelterType GetShelterType() const { return ShelterType; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Weather")
	float GetShelterRadiusUU() const { return ShelterRadiusUU; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	EWeatherShelterType ShelterType = EWeatherShelterType::CavernOverhang;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Weather")
	float ShelterRadiusUU = 600.0f;
};
