// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone740MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone740MasterSynthesisOrchestrator
 *
 * Master Milestone 740 Production Synthesis Orchestrator.
 * Validates Builds 736–740 across MemoryPalaceGraphCompilerSubsystem, NyxWhisperingVoidEmitterDirector, ContestedMemoryResolutionEvaluator, MemoryPalaceWeavingLocusActor, and Milestone 740 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone740MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone740")
	void RunMilestone740SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone740")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone740")
	bool bSynthesisPassComplete = false;
};
