// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCombatManifestoAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCombatManifestoAudioModulatedSignature, float, SilverBellToneVolume, float, LowFrequencyThrumVolume);

/**
 * UAshenCombatManifestoAtmosphericAudioModulator
 *
 * Audio Modulator shifting between High-frequency silver bell rings, Low-frequency thrums, and pure tonal blade resonance (PRS-001 Combat Blueprint V5.0).
 */
UCLASS()
class ASHENOATH_API UAshenCombatManifestoAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ManifestoAudio")
	void ModulateManifestoAudio(FName GrammarStateTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ManifestoAudio|Events")
	FOnCombatManifestoAudioModulatedSignature OnManifestoAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ManifestoAudio")
	int32 TotalAudioModulationsApplied = 0;
};
