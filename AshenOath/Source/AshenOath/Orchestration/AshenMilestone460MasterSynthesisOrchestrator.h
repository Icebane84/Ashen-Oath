// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone460MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone460MasterSynthesisOrchestrator
 *
 * Master Milestone 460 Production Synthesis Orchestrator.
 * Validates Builds 446–460 across NarrativeChoiceGraph, NarrativeChoiceUI, CompanionComboFinisherAudio, SanctuaryCrucibleUpgrade, Milestone450SynthesisOrchestrator, CrucibleUpgradeMenu, KaelenUnchainedVoidShatterExecution, EnemyPoiseBreakComponent, PoiseBreakHUD, DynamicLightingAtmosphereSubsystem, GarrettSmokeBalmSanctuary, PartyStatSynergySubsystem, and PartySynergyHUD.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone460MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone460")
	void RunMilestone460SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone460")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone460")
	bool bSynthesisPassComplete = false;
};
