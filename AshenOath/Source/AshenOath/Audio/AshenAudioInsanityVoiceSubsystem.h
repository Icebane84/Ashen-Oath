// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAudioInsanityVoiceSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInsanityVoiceBarkSignature, FName, VoiceBarkID, float, PitchMultiplier);

/**
 * UAshenAudioInsanityVoiceSubsystem
 *
 * World Subsystem playing spatial insanity voice barks and pitch-shifted auditory whispers based on player Sanity loss.
 */
UCLASS()
class ASHENOATH_API UAshenAudioInsanityVoiceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|InsanityAudio")
	void TriggerInsanityVoiceBark(float SanityPercentage);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|InsanityAudio|Events")
	FOnInsanityVoiceBarkSignature OnInsanityVoiceBark;
};
