// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone445MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone445MasterSynthesisOrchestrator
 *
 * Grand Master Milestone 445 Production Synthesis Orchestrator.
 * Validates Builds 431–445 across FullPsychologicalLoopOrchestrator, FullPsychologicalLoopAutomationTest, FullPsychologicalLoopHUD, CompanionDisagreementSystem, NonBinaryMorality, GenerativeWorldState, NonBinaryMoralityHUD, GarrettAssassinationExecution, ProceduralEncounterDirector, ProceduralEncounterHUD, SerafinaSacredGroundSanctuary, and VerticalSliceMasterDirector.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone445MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone445")
	void RunMilestone445SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone445")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone445")
	bool bSynthesisPassComplete = false;
};
