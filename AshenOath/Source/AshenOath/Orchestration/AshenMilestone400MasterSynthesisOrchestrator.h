// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone400MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone400MasterSynthesisOrchestrator
 *
 * Grand Master Milestone 400 Production Synthesis Orchestrator.
 * Validates the complete 400 C++ build codebase across all 5 Core Pillars, UMB-SYS-005, GAS abilities, UMG HUDs, and World Subsystems.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone400MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone400")
	void RunGrandMilestone400SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone400")
	int32 TotalBuildsCovered = 400;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone400")
	bool bGrandSynthesisPassComplete = false;
};
