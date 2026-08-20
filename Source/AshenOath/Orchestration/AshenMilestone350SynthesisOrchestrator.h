// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone350SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone350SynthesisOrchestrator
 *
 * Master Milestone 350 Production Synthesis Orchestrator.
 * Validates Builds 336–350 across ShatteredVirtues, InnerDemons, ScarsOfCorruption, PenitentsPath, CovenantOfWhispers, EldrinsGambit, ResonantArmaments, GeopoliticalResonance, ShadowSnare, and CorpseRun.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone350SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone350")
	void RunMilestone350SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone350")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone350")
	bool bSynthesisPassComplete = false;
};
