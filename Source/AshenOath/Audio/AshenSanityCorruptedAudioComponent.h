// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanityCorruptedAudioComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityAudioCorruptedSignature, float, SanityRatio, float, PitchMultiplier);

/**
 * UAshenSanityCorruptedAudioComponent
 *
 * Modulates auditory hallucinations, whispering pitch, and sound cue pitch multipliers
 * proportionally to player Sanity loss.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityCorruptedAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityCorruptedAudioComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanityAudio")
	void UpdateAudioCorruption(float CurrentSanity, float MaxSanity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|SanityAudio")
	float GetAudioPitchMultiplier() const { return CurrentPitchMultiplier; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityAudio")
	float MinPitch = 0.65f; // Deep distorted whispers

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityAudio")
	float MaxPitch = 1.0f; // Normal audio

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanityAudio|Events")
	FOnSanityAudioCorruptedSignature OnAudioCorrupted;

private:
	float CurrentPitchMultiplier = 1.0f;
};
