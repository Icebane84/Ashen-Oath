// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone505MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone505MasterSynthesisOrchestrator
 *
 * Master Milestone 505 Production Synthesis Orchestrator.
 * Validates Builds 491–505 across DiegeticSwordPostureComponent, SwordPostureHUD, DiegeticVisualCorruptionSubsystem, KaelenParryCounterExecution, Milestone495SynthesisOrchestrator, DiegeticEyeShaderControllerComponent, EyeShaderDebugHUD, DiegeticAudioDistortionSubsystem, SerafinaSacredBarrierExecution, GrandMasterMilestone500SynthesisOrchestrator, DiegeticFacialExpressionComponent, FacialMorphHUD, GarrettAssassinationSmokebombExecution, and ProductionHardeningSaveValidationSubsystem.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone505MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone505")
	void RunMilestone505SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone505")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone505")
	bool bSynthesisPassComplete = false;
};
