// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSerafinaHolyAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSerafinaAudioModulatedSignature, float, ChoralStemVolume, float, SacredReverbFilter);

/**
 * UAshenSerafinaHolyAtmosphericAudioModulator
 *
 * Modulator swelling choral & sacred audio stems during Serafina's Radiant Purge execution (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaHolyAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAudio")
	void ModulateSerafinaHolyAudio(bool bIsPurgeActive, float EmpathicResonanceLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAudio|Events")
	FOnSerafinaAudioModulatedSignature OnSerafinaAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaAudio")
	int32 TotalAudioModulationsApplied = 0;
};
