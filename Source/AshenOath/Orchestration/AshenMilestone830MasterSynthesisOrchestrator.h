// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone830MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone830MasterSynthesisOrchestrator
 *
 * Master Milestone 830 Production Synthesis Orchestrator.
 * Validates Builds 821–830 across TemporalDilationDesaturationSubsystem, DualSenseAdaptiveTriggerHapticFrictionComponent, ParasiteGutturalHeartbeatAudioModulator, SurrenderUnchainedResolutionEvaluator, DualSenseHapticFrictionAutomationTest, ResistWillpowerResolutionEvaluator, GlassShatterSilverDustVFXEmitterActor, SomaticIntrusionPanicEvaluator, DiegeticPromptInWorldAnnotationBroadcaster, and Milestone 830 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone830MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone830")
	void RunMilestone830SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone830")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone830")
	bool bSynthesisPassComplete = false;
};
