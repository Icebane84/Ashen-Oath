// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenAtmosphericCombatAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAtmosphericCombatAudioModulatedSignature, float, MusicPitchFilter, float, WhisperEmitterVolume);

/**
 * UAshenAtmosphericCombatAudioModulator
 *
 * Modulator altering ambient combat music & whisper emitters during Dark Mode / Unchained Berserk (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenAtmosphericCombatAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AudioModulation")
	void ModulateAtmosphericCombatAudio(bool bIsUnchainedBerserk, float NarrativeEntropyLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AudioModulation|Events")
	FOnAtmosphericCombatAudioModulatedSignature OnAtmosphericAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AudioModulation")
	int32 TotalAudioModulationsApplied = 0;
};
