// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone760MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone760MasterSynthesisOrchestrator
 *
 * Master Milestone 760 Production Synthesis Orchestrator.
 * Validates Builds 756–760 across BlackwoodBridgeLevelManagerActor, MalakorVoidSmashBossPhaseController, DialogueChoiceMoralityEvaluator, AshenOathCampfireRestAreaActor, and Milestone 760 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone760MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone760")
	void RunMilestone760SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone760")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone760")
	bool bSynthesisPassComplete = false;
};
