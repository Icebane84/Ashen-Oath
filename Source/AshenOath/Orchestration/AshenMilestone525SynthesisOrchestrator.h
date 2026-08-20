// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone525SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone525SynthesisOrchestrator
 *
 * Milestone 525 Production Synthesis Orchestrator.
 * Validates Builds 521–525 across DiegeticArmorScuffDecalSubsystem, ArmorScuffDebugHUD, CompanionTacticalCoverSubsystem, GarrettSmokeScreenRelocationExecution, and Milestone 525 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone525SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone525")
	void RunMilestone525SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone525")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone525")
	bool bSynthesisPassComplete = false;
};
