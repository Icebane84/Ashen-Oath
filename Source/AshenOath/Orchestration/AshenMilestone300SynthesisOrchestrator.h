// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone300SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone300SynthesisOrchestrator
 *
 * Master Production Synthesis Orchestrator for MILESTONE 300.
 * Validates Builds 1–300 across all core gameplay, companion AI, GAS abilities, audio subsystems, HUD UMG widgets, and QA automation suites.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone300SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone300")
	void RunMasterMilestone300SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone300")
	int32 TotalBuildsCovered = 300;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone300")
	bool bMasterSynthesisPassComplete = false;
};
