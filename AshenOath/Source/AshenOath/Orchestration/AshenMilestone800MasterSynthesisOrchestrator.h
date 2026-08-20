// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone800MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone800MasterSynthesisOrchestrator
 *
 * Master Milestone 800 Production Synthesis Orchestrator.
 * Validates Builds 796–800 across CombatIdentitySixPillarsEvaluator, CombatGrammarFeedbackComponent, OathbringerThreeStageLifecycleComponent, AegisGlancingDeflectionComponent, and Milestone 800 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone800MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone800")
	void RunMilestone800SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone800")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone800")
	bool bSynthesisPassComplete = false;
};
