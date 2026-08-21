// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenControllerVibrationAdapterComponent.generated.h"

/**
 * UAshenControllerVibrationAdapterComponent
 * 
 * Smooths and interps low-frequency and high-frequency motor amplitudes.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenControllerVibrationAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenControllerVibrationAdapterComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Sets target motor vibration levels */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	void SetTargetVibration(float LeftMotor, float RightMotor);

	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	float GetCurrentLeftMotor() const { return CurrentLeft; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	float GetCurrentRightMotor() const { return CurrentRight; }

private:
	float CurrentLeft = 0.0f;
	float CurrentRight = 0.0f;
	float DesiredLeft = 0.0f;
	float DesiredRight = 0.0f;
};
