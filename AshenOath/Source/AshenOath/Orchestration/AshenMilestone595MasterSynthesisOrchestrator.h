// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone595MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone595MasterSynthesisOrchestrator
 *
 * Master Milestone 595 Production Synthesis Orchestrator.
 * Validates Builds 581–595 across AbominationBossPhaseSubsystem, AegisBarrierComponent, AlchemicalCraftingBenchActor, AlchemicalInfusionSubsystem, Milestone585SynthesisOrchestrator, ArmorScuffDecalSubsystem, AtmosphericSanityModifierVolume, BlessingBuffComponent, BossDeathCinematicDirectorSubsystem, BurdenOfCommandComponent, CombatDebrisComponent, CompanionDivergenceWarningWidget, ConsecratedGroundSanctuaryComponent, and Milestone 595 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone595MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone595")
	void RunMilestone595SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone595")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone595")
	bool bSynthesisPassComplete = false;
};
