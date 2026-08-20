// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone370SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone370SynthesisOrchestrator
 *
 * Milestone 370 Production Synthesis Orchestrator.
 * Validates Builds 366–370 across EmberEconomyCrafting, EnvironmentalAnchoring, UnreliableNarratorCombat, and GaslightingGhouls.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone370SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone370")
	void RunMilestone370SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone370")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone370")
	bool bSynthesisPassComplete = false;
};
