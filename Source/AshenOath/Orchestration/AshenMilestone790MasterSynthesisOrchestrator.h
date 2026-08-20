// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone790MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone790MasterSynthesisOrchestrator
 *
 * Master Milestone 790 Production Synthesis Orchestrator.
 * Validates Builds 781–790 across OathbringerRunicEngravingComponent, OathbringerHeavyOverheadCleaveAbility, AnvilWeaponUpgradeLocusActor, OathbringerResonanceSynergyCalculator, OathbringerUpgradeAutomationTest, OathbringerMasteryProgressionSubsystem, OathbringerRunicGlowVFXAnchorActor, OathbringerTargetingPriorityDirector, WeaponForgeSparkVisualLocusActor, and Milestone 790 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone790MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone790")
	void RunMilestone790SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone790")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone790")
	bool bSynthesisPassComplete = false;
};
