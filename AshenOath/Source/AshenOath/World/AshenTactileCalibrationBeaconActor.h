// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenTactileCalibrationBeaconActor.generated.h"

class UStaticMeshComponent;

/**
 * AAshenTactileCalibrationBeaconActor
 * 
 * Interactive world beacon actor allowing developers and players to calibrate
 * adaptive trigger resistance curves and controller speaker audio.
 */
UCLASS()
class ASHENOATH_API AAshenTactileCalibrationBeaconActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenTactileCalibrationBeaconActor();

	virtual void BeginPlay() override;

	/** Triggers test calibration burst */
	UFUNCTION(BlueprintCallable, Category = "Ashen|World|Haptics")
	void TriggerCalibrationBurst(bool bTestLeftTrigger);

	UFUNCTION(BlueprintPure, Category = "Ashen|World|Haptics")
	bool IsBeaconActive() const { return bBeaconActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BeaconMesh;

private:
	bool bBeaconActive = false;
};
