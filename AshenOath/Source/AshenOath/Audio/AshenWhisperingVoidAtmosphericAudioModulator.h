// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenWhisperingVoidAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVoidAudioModulatedSignature, float, DissonantStemVolume, float, LowPassCutoffFreq);

/**
 * UAshenWhisperingVoidAtmosphericAudioModulator
 *
 * Modulator shifting ambient audio stems toward dissonant void frequencies (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API UAshenWhisperingVoidAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VoidAudio")
	void ModulateVoidAudio(float VoidErosionIntensity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VoidAudio|Events")
	FOnVoidAudioModulatedSignature OnVoidAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VoidAudio")
	int32 TotalAudioModulationsApplied = 0;
};
