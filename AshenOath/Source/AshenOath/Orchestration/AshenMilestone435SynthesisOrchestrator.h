// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone435SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone435SynthesisOrchestrator
 *
 * Milestone 435 Production Synthesis Orchestrator.
 * Validates Builds 431–435 across FullPsychologicalLoopOrchestrator, FullPsychologicalLoopHUD, CompanionDisagreementSystem, and Milestone 435 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone435SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone435")
	void RunMilestone435SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone435")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone435")
	bool bSynthesisPassComplete = false;
};
