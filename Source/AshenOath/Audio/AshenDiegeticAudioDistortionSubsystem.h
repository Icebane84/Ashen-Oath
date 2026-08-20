// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenDiegeticAudioDistortionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAudioDistortionModulatedSignature, float, PitchShiftMultiplier, float, TinnitusVolume);

/**
 * UAshenDiegeticAudioDistortionSubsystem
 *
 * World Subsystem applying procedural pitch shift, low-pass filter, and tinnitus audio distortion during low sanity/high trauma.
 */
UCLASS()
class ASHENOATH_API UAshenDiegeticAudioDistortionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioDistortion")
	void ModulateAudioDistortionForSanity(float SanityPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioDistortion|Events")
	FOnAudioDistortionModulatedSignature OnAudioDistortionModulated;
};
