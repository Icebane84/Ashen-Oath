// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone680SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone680SynthesisOrchestrator
 *
 * Milestone 680 Production Synthesis Orchestrator.
 * Validates Builds 676–680 across AegisStaggerCalculator, DevilsBargainTrustAtrophyDirector, WillpowerStaminaRegenModifier, SomaticCombatFeedWidget, and Milestone 680 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone680SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone680")
	void RunMilestone680SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone680")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone680")
	bool bSynthesisPassComplete = false;
};
