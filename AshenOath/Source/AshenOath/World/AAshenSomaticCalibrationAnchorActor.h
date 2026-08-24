// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AAshenSomaticCalibrationAnchorActor.generated.h"

class USphereComponent;

/**
 * AAshenSomaticCalibrationAnchorActor
 * 
 * Environmental spatial anchor setting ambient soot deposition rate multipliers in specific zones.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticCalibrationAnchorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSomaticCalibrationAnchorActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Somatics")
	float GetAmbientSootRateMultiplier() const { return AmbientSootRateMultiplier; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* ZoneSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|World|Somatics")
	float AmbientSootRateMultiplier = 1.5f;
};
