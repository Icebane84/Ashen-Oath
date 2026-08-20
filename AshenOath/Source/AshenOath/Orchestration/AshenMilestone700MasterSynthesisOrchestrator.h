// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone700MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone700MasterSynthesisOrchestrator
 *
 * Master Milestone 700 Production Synthesis Orchestrator.
 * Validates Builds 696–700 across GarrettSmokeBalmSanctuaryComponent, GarrettTripwireDetonationSystem, GarrettTripleDaggerFanAbility, CANPragmaticAdaptationEvaluator, and Milestone 700 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone700MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone700")
	void RunMilestone700SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone700")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone700")
	bool bSynthesisPassComplete = false;
};
