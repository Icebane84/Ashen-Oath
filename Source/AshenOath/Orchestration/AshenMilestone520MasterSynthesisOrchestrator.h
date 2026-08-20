// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone520MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone520MasterSynthesisOrchestrator
 *
 * Master Milestone 520 Production Synthesis Orchestrator.
 * Validates Builds 506–520 across SymbioticPeakResonanceSilenceComponent, PeakResonanceHUD, FailureMemoryPsychicEchoSubsystem, KaelenLethalSilentDualExecution, Milestone510SynthesisOrchestrator, SerafinaIdentityCompilerSubsystem, CampfireInterpretiveLensMenu, SoulConstellationDependencyGraphComponent, SerafinaLorekeeperInsightExecution, VirtueFractureConsequenceComponent, VirtueFractureHUD, GarrettSilentAssassinationExecution, and EngineSpecAxiomValidationSubsystem.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone520MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone520")
	void RunMilestone520SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone520")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone520")
	bool bSynthesisPassComplete = false;
};
