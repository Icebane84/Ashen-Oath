// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone180SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone180SynthesisOrchestrator
 *
 * Milestone 180 Production Synthesis Pass.
 * Validates the full vertical slice pipeline for Builds 173–179:
 *   - Kaelen Parry Counter Component (B173)
 *   - Garrett Trap Network Component (B174)
 *   - Serafina Aura Field Component (B175)
 *   - Dynamic Music Subsystem (B176)
 *   - Compass Bar UMG Widget (B177)
 *   - Companion Systems Automation Tests (B178)
 *   - This Orchestrator (B179)
 */
UCLASS()
class ASHENOATH_API UAshenMilestone180SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone180")
	void RunMilestone180SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone180")
	int32 TotalBuildsCovered = 7;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone180")
	bool bSynthesisPassComplete = false;
};
