// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone580MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone580MasterSynthesisOrchestrator
 *
 * Master Milestone 580 Production Synthesis Orchestrator.
 * Validates Builds 566–580 across VeilHoundAmbushSubsystem, VirtueFractureHUD, WeaponEnchantmentComponent, WeatherAudioModulationSubsystem, Milestone570SynthesisOrchestrator, WeatherParticleFXSubsystem, WhispererEnemy, WhisperingWindEmitterComponent, WhisperingWindsOracleSubsystem, WorldBossPhaseControllerComponent, SanctuaryBlessingRegistrySubsystem, SanctuaryVendorEconomySubsystem, ShadowfenEncounterDirectorSubsystem, and Milestone 580 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone580MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone580")
	void RunMilestone580SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone580")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone580")
	bool bSynthesisPassComplete = false;
};
