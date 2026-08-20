// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone730MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone730MasterSynthesisOrchestrator
 *
 * Master Milestone 730 Production Synthesis Orchestrator.
 * Validates Builds 721–730 across SerafinaDivineJudgmentAbility, SerafinaEmpathicResonanceBuffComponent, SacredGroundSanctuaryZoneActor, SerafinaHolyNovaBurstAbility, SerafinaAbilitiesAutomationTest, SerafinaHarmonicAuraSubsystem, RadiantBarrierVFXAnchorActor, SerafinaSunPulseSanctuaryAbility, SerafinaEmpathicSupportPriorityDirector, and Milestone 730 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone730MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone730")
	void RunMilestone730SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone730")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone730")
	bool bSynthesisPassComplete = false;
};
