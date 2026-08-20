// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone570SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone570SynthesisOrchestrator
 *
 * Milestone 570 Production Synthesis Orchestrator.
 * Validates Builds 566–570 across VeilHoundAmbushSubsystem, VirtueFractureHUD, WeaponEnchantmentComponent, WeatherAudioModulationSubsystem, and Milestone 570 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone570SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone570")
	void RunMilestone570SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone570")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone570")
	bool bSynthesisPassComplete = false;
};
