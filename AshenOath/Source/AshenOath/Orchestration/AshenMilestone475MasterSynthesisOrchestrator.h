// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone475MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone475MasterSynthesisOrchestrator
 *
 * Master Milestone 475 Production Synthesis Orchestrator.
 * Validates Builds 461–475 across DiegeticBreathingComponent, DiegeticBreathingHUD, CombatEnvironmentalImpactSubsystem, KaelenGroundShatterBurstExecution, Milestone465SynthesisOrchestrator, DiegeticArmorDamageSubsystem, ArmorDamageHUD, CompanionEmotionalResidueComponent, SerafinaRadiantPurgeNova, MindscapeTransitionSubsystem, MindscapeHUD, GarrettTripwireDetonation, and DiegeticLocomotionPostureComponent.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone475MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone475")
	void RunMilestone475SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone475")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone475")
	bool bSynthesisPassComplete = false;
};
