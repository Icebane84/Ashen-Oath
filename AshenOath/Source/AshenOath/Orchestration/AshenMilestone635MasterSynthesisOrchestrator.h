// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone635MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone635MasterSynthesisOrchestrator
 *
 * Master Milestone 635 Production Synthesis Orchestrator.
 * Validates Builds 616–635 across InterpretationEngineSubsystem, IntegrativeMemoryPassComponent, HermeneuticFragmentationComponent, InterpretiveClaritySubsystem, Milestone620SynthesisOrchestrator, SeparationVelocityCalculator, UncertaintyExploitationDirector, PlausibleDestructivenessEvaluator, EntropyOfMeaningSubsystem, ContestedInterpretationWidget, InterpretiveLensSelectorComponent, MechanicalHonestyRuleEnforcer, DualMirrorCompilerPassOrchestrator, MemoryPalaceNodeAnchorActor, WhisperingVoidErosionVolume, IdentityCompilationMutator, PsychologicalRuntimeBroadcaster, and Milestone 635 Verification (UMB-INT-001).
 */
UCLASS()
class ASHENOATH_API UAshenMilestone635MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone635")
	void RunMilestone635SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone635")
	int32 TotalBuildsCovered = 20;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone635")
	bool bSynthesisPassComplete = false;
};
