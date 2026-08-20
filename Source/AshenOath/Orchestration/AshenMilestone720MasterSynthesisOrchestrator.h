// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone720MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone720MasterSynthesisOrchestrator
 *
 * Master Milestone 720 Production Synthesis Orchestrator.
 * Validates Builds 716–720 across SerafinaSacredBarrierComponent, SerafinaRadiantPurgeNovaSubsystem, SerafinaLorekeeperInsightEvaluator, CANSanctuarySurplusMasteryCalculator, and Milestone 720 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone720MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone720")
	void RunMilestone720SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone720")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone720")
	bool bSynthesisPassComplete = false;
};
