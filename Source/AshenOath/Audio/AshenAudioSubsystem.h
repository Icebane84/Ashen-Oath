// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenAudioSubsystem.generated.h"

class USoundBase;

/**
 * UAshenAudioSubsystem
 * GameInstanceSubsystem serving as the central coordinator for all spatial (3D)
 * and static (2D) sound playback requests.
 */
UCLASS()
class ASHENOATH_API UAshenAudioSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Play sound at a 3D location */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void PlaySpatialSound(USoundBase* Sound, FVector Position, float VolumeMultiplier = 1.0f, float PitchMultiplier = 1.0f);

	/** Play 2D non-spatialized UI or background sound */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void PlayStaticSound(USoundBase* Sound, float VolumeMultiplier = 1.0f, float PitchMultiplier = 1.0f);

private:
	UFUNCTION()
	void HandleSpatialSoundRequested(USoundBase* Sound, FVector Position, float VolumeMultiplier, float PitchMultiplier);
};
