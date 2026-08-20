// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAudioSanityBreakSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSanityBreakAudioTriggeredSignature, bool, bIsMuffled, float, HeartbeatBPM);

/**
 * UAshenAudioSanityBreakSubsystem
 *
 * World Subsystem triggering deafening tinnitus audio muffling, reverse reverb sweeps, and heartbeat pulses during Sanity Break events.
 */
UCLASS()
class ASHENOATH_API UAshenAudioSanityBreakSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanityAudio")
	void TriggerSanityBreakAudioEffect(bool bEnableMuffle, float TargetBPM);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanityAudio|Events")
	FOnSanityBreakAudioTriggeredSignature OnSanityBreakAudioTriggered;

private:
	bool bAudioMuffled = false;
};
