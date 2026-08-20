// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone670MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone670MasterSynthesisOrchestrator
 *
 * Master Milestone 670 Production Synthesis Orchestrator.
 * Validates Builds 661–670 across GlancingDeflectionParryEvaluator, HalfSwordBraceStanceComponent, CrownGuardCounterBindAbility, MartyrGuardAllyInterceptComponent, DefensiveArsenalAutomationTest, UnchainedBerserkModeController, SpiritualScarringHealthStainSubsystem, SmiteRiposteShockwaveComponent, SanctuarySurplusMasteryCalculator, and Milestone 670 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone670MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone670")
	void RunMilestone670SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone670")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone670")
	bool bSynthesisPassComplete = false;
};
