// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenDualSenseHapticSubsystem.generated.h"

/**
 * UAshenDualSenseHapticSubsystem
 * 
 * Central world subsystem coordinating PlayStation 5 / PC DualSense haptics,
 * adaptive trigger arbitration, and controller speaker audio routing.
 */
UCLASS()
class ASHENOATH_API UAshenDualSenseHapticSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenDualSenseHapticSubsystem();

	/** Applies an adaptive trigger configuration */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	void ApplyTriggerConfig(bool bIsLeftTrigger, const FDualSenseTriggerConfig& Config);

	/** Routes a tactile whisper through the controller speaker */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	void RouteTactileWhisper(const FTactileWhisperPayload& Payload);

	/** Pulses directional tactile rumble to indicate flanking threats */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Haptics")
	void PulseDirectionalHaptics(float LeftIntensity, float RightIntensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	FDualSenseTriggerConfig GetLeftTriggerConfig() const { return LeftConfig; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Haptics")
	FDualSenseTriggerConfig GetRightTriggerConfig() const { return RightConfig; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Haptics")
	FOnTriggerConfigChanged OnTriggerConfigChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Haptics")
	FOnTactileWhisperEmitted OnTactileWhisperEmitted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Haptics")
	FOnDirectionalTactilePulse OnDirectionalTactilePulse;

private:
	FDualSenseTriggerConfig LeftConfig;
	FDualSenseTriggerConfig RightConfig;
};
