// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone310SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone310SynthesisOrchestrator
 *
 * Milestone 310 Production Synthesis Orchestrator for UMB-SYS-005.
 * Validates Builds 301–310 across SoulStateVector, UnreliableStateMachine, HeartstoneCrucible, CompanionDiagnosticBifurcation, FalseConfidenceDeception, and DualHarmonic audio stems.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone310SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone310")
	void RunMilestone310SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone310")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone310")
	bool bSynthesisPassComplete = false;
};
