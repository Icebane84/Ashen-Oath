// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone320SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone320SynthesisOrchestrator
 *
 * Milestone 320 Production Synthesis Orchestrator.
 * Validates Builds 311–320 across OathBurn, ResonanceCombatStances, LivingOaths, SanityBreakEvents, MemoryWeaving, and Tinnitus audio muffling.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone320SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone320")
	void RunMilestone320SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone320")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone320")
	bool bSynthesisPassComplete = false;
};
