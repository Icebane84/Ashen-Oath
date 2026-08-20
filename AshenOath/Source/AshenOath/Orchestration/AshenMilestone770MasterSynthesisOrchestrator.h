// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone770MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone770MasterSynthesisOrchestrator
 *
 * Master Milestone 770 Production Synthesis Orchestrator.
 * Validates Builds 761–770 across BlackwoodCorruptedMistVolumeComponent, MalakorPhaseTransitionAbility, CampfireDialogueTriggerZoneActor, BlackwoodEncounterRewardCalculator, BlackwoodEncounterAutomationTest, Act01QuestProgressionSubsystem, BridgeCollapseVFXAnchorActor, AbominationMalakorAIPriorityDirector, CampfireEmbersVisualLocusActor, and Milestone 770 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone770MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone770")
	void RunMilestone770SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone770")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone770")
	bool bSynthesisPassComplete = false;
};
