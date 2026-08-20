// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone675MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone675MasterSynthesisOrchestrator
 *
 * Master Milestone 675 Production Synthesis Orchestrator.
 * Validates Builds 656–675 across AegisWhiteFlameDefensiveComponent, DevilsBargainTransformationSubsystem, WillpowerRewardMatrixSubsystem, TrinityDoctrineCompanionSynergyComponent, Milestone660SynthesisOrchestrator, GlancingDeflectionParryEvaluator, HalfSwordBraceStanceComponent, CrownGuardCounterBindAbility, MartyrGuardAllyInterceptComponent, DefensiveArsenalAutomationTest, UnchainedBerserkModeController, SpiritualScarringHealthStainSubsystem, SmiteRiposteShockwaveComponent, SanctuarySurplusMasteryCalculator, Milestone670MasterSynthesisOrchestrator, OathbringerGreatswordActor, LethalInterceptCrisisPromptActor, HarmonicPurificationSynergySubsystem, TacticalFlankInterceptDirector, and Milestone 675 Verification (PRS-001 Combat Blueprint).
 */
UCLASS()
class ASHENOATH_API UAshenMilestone675MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone675")
	void RunMilestone675SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone675")
	int32 TotalBuildsCovered = 20;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone675")
	bool bSynthesisPassComplete = false;
};
