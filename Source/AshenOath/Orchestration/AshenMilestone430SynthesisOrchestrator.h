// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone430SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone430SynthesisOrchestrator
 *
 * Master Milestone 430 Production Synthesis Orchestrator.
 * Validates Builds 416–430 across FStateTreeTask_EvaluateAction, FStateTreeTask_ExecuteAbility, ThreatPerception, SoulStateVectorDecay, CognitiveAIDebug, SunfallNova, SanctuaryBlessingRegistry, DynamicWeatherVFX, WhirlwindExecution, and ConstellationPerkUnlock.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone430SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone430")
	void RunMilestone430SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone430")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone430")
	bool bSynthesisPassComplete = false;
};
