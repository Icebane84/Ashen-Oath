// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone160SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone160SynthesisOrchestrator
 *
 * Milestone 160 Production Synthesis Pass.
 * Validates the full vertical slice pipeline for Builds 154–163:
 *   - Level Streaming (B154)
 *   - Guard Break Counter GAS (B155)
 *   - Sanctuary Blessing Component (B156)
 *   - Smoke Warp GAS (B157)
 *   - Mindscape Audio/Visual Distorter (B158)
 *   - Loot Container Subsystem (B159)
 *   - Stamina Exhaustion Component (B160)
 *   - Boss Health Bar Widget (B161)
 *   - Level Streaming & Boss Automation Tests (B162)
 */
UCLASS()
class ASHENOATH_API UAshenMilestone160SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone160")
	void RunMilestone160SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone160")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone160")
	bool bSynthesisPassComplete = false;
};
