// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenOathbringerResonanceAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResonanceAudioModulatedSignature, float, MetallicRingPitchMultiplier, float, HolyHarmonicStemVolume);

/**
 * UAshenOathbringerResonanceAtmosphericAudioModulator
 *
 * Modulator triggering metallic ringing & holy harmonic audio stems (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerResonanceAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonanceAudio")
	void ModulateResonanceAudio(float BladeResonancePercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonanceAudio|Events")
	FOnResonanceAudioModulatedSignature OnResonanceAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ResonanceAudio")
	int32 TotalAudioModulationsApplied = 0;
};
