// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone495SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone495SynthesisOrchestrator
 *
 * Milestone 495 Production Synthesis Orchestrator.
 * Validates Builds 491–495 across DiegeticSwordPostureComponent, SwordPostureHUD, DiegeticVisualCorruptionSubsystem, KaelenParryCounterExecution, and Milestone 495 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone495SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone495")
	void RunMilestone495SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone495")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone495")
	bool bSynthesisPassComplete = false;
};
