// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone690MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone690MasterSynthesisOrchestrator
 *
 * Master Milestone 690 Production Synthesis Orchestrator.
 * Validates Builds 681–690 across BehemothKnockdownInterceptionEvaluator, CrossguardThrowPositionalAbility, MartyrGuardCorruptionSpikeCalculator, SpiritualStainSanctuaryCleanser, AegisAndStainAutomationTest, OathbringerResonanceTuningComponent, SerafinaEmpathicExhaustionModulator, GarrettFlankEQSEvaluator, WhiteFlameShockwaveEmitterComponent, and Milestone 690 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone690MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone690")
	void RunMilestone690SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone690")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone690")
	bool bSynthesisPassComplete = false;
};
