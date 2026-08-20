// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone465SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone465SynthesisOrchestrator
 *
 * Milestone 465 Production Synthesis Orchestrator.
 * Validates Builds 461–465 across DiegeticBreathingComponent, DiegeticBreathingHUD, CombatEnvironmentalImpactSubsystem, KaelenGroundShatterBurstExecution, and Milestone 465 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone465SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone465")
	void RunMilestone465SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone465")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone465")
	bool bSynthesisPassComplete = false;
};
