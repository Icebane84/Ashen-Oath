// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone365SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone365SynthesisOrchestrator
 *
 * Master Milestone 365 Production Synthesis Orchestrator.
 * Validates Builds 351–365 across PrismaticRealmVeil, CompanionFatigue, CompanionTrustDivergence, ResonanceAnchoringSync, AtmosphericCorruption, SyncedHolyBurst, SyncedShadowStrike, RemnantChronicles, CognitiveAI, BossPhases, and AudioVeil.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone365SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone365")
	void RunMilestone365SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone365")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone365")
	bool bSynthesisPassComplete = false;
};
