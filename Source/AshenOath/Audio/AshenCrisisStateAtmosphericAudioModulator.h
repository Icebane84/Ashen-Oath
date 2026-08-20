// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCrisisStateAtmosphericAudioModulator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrisisStateAudioModulatedSignature, float, AcousticVacuumDb, float, SilverBellVolume);

/**
 * UAshenCrisisStateAtmosphericAudioModulator
 *
 * Audio Modulator executing smooth transitions between acoustic vacuum, parasite whispers, and resonant silver bell tones (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenCrisisStateAtmosphericAudioModulator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CrisisAudio")
	void ModulateCrisisAudioState(FName ResolutionTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CrisisAudio|Events")
	FOnCrisisStateAudioModulatedSignature OnCrisisAudioModulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CrisisAudio")
	int32 TotalAudioTransitionsApplied = 0;
};
