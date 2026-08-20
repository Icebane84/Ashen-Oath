// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone620SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone620SynthesisOrchestrator
 *
 * Milestone 620 Production Synthesis Orchestrator.
 * Validates Builds 616–620 across InterpretationEngineSubsystem, IntegrativeMemoryPassComponent, HermeneuticFragmentationComponent, and InterpretiveClaritySubsystem.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone620SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone620")
	void RunMilestone620SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone620")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone620")
	bool bSynthesisPassComplete = false;
};
