// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenBlackwoodBridgeAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBlackwoodAudioModulatedSignature, float, BossCombatMusicVolume, float, ThunderRainVolume);

/**
 * UAshenBlackwoodBridgeAtmosphericAudioModulator
 *
 * Modulator swelling intense boss battle music & environmental storm stems (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API UAshenBlackwoodBridgeAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BlackwoodAudio")
	void ModulateBlackwoodAudio(bool bInBossCombat, float StormIntensity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BlackwoodAudio|Events")
	FOnBlackwoodAudioModulatedSignature OnBlackwoodAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|BlackwoodAudio")
	int32 TotalAudioModulationsApplied = 0;
};
