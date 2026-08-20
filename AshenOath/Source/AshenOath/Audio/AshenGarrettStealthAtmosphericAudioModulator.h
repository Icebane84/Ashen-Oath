// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenGarrettStealthAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGarrettAudioModulatedSignature, float, TensionStemVolume, float, FootstepDampingFactor);

/**
 * UAshenGarrettStealthAtmosphericAudioModulator
 *
 * Modulator altering ambient audio stems during Garrett's stealth & smoke screen execution (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API UAshenGarrettStealthAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettAudio")
	void ModulateGarrettStealthAudio(bool bIsStealthed, float ThreatLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettAudio|Events")
	FOnGarrettAudioModulatedSignature OnGarrettAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GarrettAudio")
	int32 TotalAudioModulationsApplied = 0;
};
