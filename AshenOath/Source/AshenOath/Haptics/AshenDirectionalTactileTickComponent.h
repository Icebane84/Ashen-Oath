// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenDirectionalTactileTickComponent.generated.h"

/**
 * UAshenDirectionalTactileTickComponent
 * 
 * Computes Left/Right controller grip motor vibration bias based on relative threat angles.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDirectionalTactileTickComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDirectionalTactileTickComponent();

	/** Computes directional grip intensities from player to threat location */
	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	void CalculateDirectionalTicks(
		const FVector& PlayerForward,
		const FVector& ThreatDirection,
		float ThreatIntensity,
		float& OutLeftMotor,
		float& OutRightMotor) const;
};
