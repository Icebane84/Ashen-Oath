// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone490MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone490MasterSynthesisOrchestrator
 *
 * Master Milestone 490 Production Synthesis Orchestrator.
 * Validates Builds 476–490 across BossMultiPhaseTransitionComponent, BossPhaseHUD, BossArenaEnvironmentalScriptSubsystem, BossAbominationVoidSmashExecution, Milestone480SynthesisOrchestrator, EnemyFamilyBlightGhoulComponent, SwarmThreatHUD, EnemyFamilyAshWalkerComponent, AshWalkerShieldBashExecution, EnemyFamilyVeilHoundComponent, VeilHoundAmbushHUD, VeilHoundPounceExecution, and BossDeathCinematicDirectorSubsystem.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone490MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone490")
	void RunMilestone490SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone490")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone490")
	bool bSynthesisPassComplete = false;
};
