// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone380SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone380SynthesisOrchestrator
 *
 * Master Milestone 380 Production Synthesis Orchestrator.
 * Validates Builds 366–380 across EmberEconomyCrafting, EnvironmentalAnchoring, UnreliableNarratorCombat, GaslightingGhouls, FocusModeInvestigation, ResonanceShiftAttack, PsychicEchoes, ShiftingAllegiance, RadiantPurgeNova, and SanctuaryRestoration.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone380SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone380")
	void RunMilestone380SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone380")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone380")
	bool bSynthesisPassComplete = false;
};
