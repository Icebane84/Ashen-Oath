// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone170SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone170SynthesisOrchestrator
 *
 * Milestone 170 Production Synthesis Pass.
 * Validates and acknowledges the full vertical slice pipeline for Builds 164–173:
 *   - Enemy Spawn Director Component (B164)
 *   - Serafina Holy Nova GAS (B165)
 *   - Respawn Subsystem (B166)
 *   - Item Pickup Actor (B167)
 *   - Ashbringer Charged Slam GAS (B168)
 *   - Stamina Bar UMG Widget (B169)
 *   - Combat Replay Component (B170)
 *   - Building Blocks Automation Tests (B171)
 *   - This Orchestrator (B172)
 */
UCLASS()
class ASHENOATH_API UAshenMilestone170SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone170")
	void RunMilestone170SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone170")
	int32 TotalBuildsCovered = 9;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone170")
	bool bSynthesisPassComplete = false;
};
