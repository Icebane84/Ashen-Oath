// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone820MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone820MasterSynthesisOrchestrator
 *
 * Master Milestone 820 Production Synthesis Orchestrator.
 * Validates Builds 816–820 across DevilsBargainDiegeticUIPromptSubsystem, DiegeticVeinCreepShaderComponent, ForearmRunicInputEtchVisualLocusActor, SubliminalPeripheralThoughtOverlayComponent, and Milestone 820 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone820MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone820")
	void RunMilestone820SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone820")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone820")
	bool bSynthesisPassComplete = false;
};
