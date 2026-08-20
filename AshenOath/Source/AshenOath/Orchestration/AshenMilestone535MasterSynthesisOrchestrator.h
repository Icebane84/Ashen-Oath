// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone535MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone535MasterSynthesisOrchestrator
 *
 * Master Milestone 535 Production Synthesis Orchestrator.
 * Validates Builds 521–535 across DiegeticArmorScuffDecalSubsystem, ArmorScuffDebugHUD, CompanionTacticalCoverSubsystem, GarrettSmokeScreenRelocationExecution, Milestone525SynthesisOrchestrator, EnvironmentalWeatherAtmosphereSubsystem, WeatherAtmosphereHUD, PartyMoralResonanceSubsystem, KaelenHolyAvengerCleaveExecution, DiegeticStaminaPulseAudioComponent, StaminaPulseHUD, SerafinaSanctuaryAuraExecution, and ProductionHardeningCrashReportSubsystem.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone535MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone535")
	void RunMilestone535SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone535")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone535")
	bool bSynthesisPassComplete = false;
};
