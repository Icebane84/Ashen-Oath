// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone710MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone710MasterSynthesisOrchestrator
 *
 * Master Milestone 710 Production Synthesis Orchestrator.
 * Validates Builds 701–710 across GarrettShadowStepStealthComponent, GarrettPoisonBladeExecutionAbility, GarrettShadowSnareTrapActor, GarrettFlashPowderBlindEvaluator, GarrettAbilitiesAutomationTest, GarrettTacticalCooperationSubsystem, SmokeBalmSanctuaryZoneVolume, GarrettAssassinationDashAbility, GarrettCrowdControlPriorityDirector, and Milestone 710 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone710MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone710")
	void RunMilestone710SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone710")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone710")
	bool bSynthesisPassComplete = false;
};
