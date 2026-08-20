// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone420SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone420SynthesisOrchestrator
 *
 * Milestone 420 Production Synthesis Orchestrator.
 * Validates Builds 416–421 across FStateTreeTask_EvaluateAction, FStateTreeTask_ExecuteAbility, ThreatPerception, SoulStateVectorDecay, and CognitiveAIDebug UI.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone420SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone420")
	void RunMilestone420SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone420")
	int32 TotalBuildsCovered = 6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone420")
	bool bSynthesisPassComplete = false;
};
