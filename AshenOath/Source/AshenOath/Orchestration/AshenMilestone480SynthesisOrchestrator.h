// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone480SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone480SynthesisOrchestrator
 *
 * Milestone 480 Production Synthesis Orchestrator.
 * Validates Builds 476–480 across BossMultiPhaseTransitionComponent, BossPhaseHUD, BossArenaEnvironmentalScriptSubsystem, BossAbominationVoidSmashExecution, and Milestone 480 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone480SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone480")
	void RunMilestone480SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone480")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone480")
	bool bSynthesisPassComplete = false;
};
