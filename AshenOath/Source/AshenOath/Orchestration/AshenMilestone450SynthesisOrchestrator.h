// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone450SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone450SynthesisOrchestrator
 *
 * Milestone 450 Production Synthesis Orchestrator.
 * Validates Builds 446–450 across NarrativeChoiceGraph, NarrativeChoiceUI, CompanionComboFinisherAudio, SanctuaryCrucibleUpgrade, and Milestone 450 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone450SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone450")
	void RunMilestone450SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone450")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone450")
	bool bSynthesisPassComplete = false;
};
