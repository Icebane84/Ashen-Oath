// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone810MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone810MasterSynthesisOrchestrator
 *
 * Master Milestone 810 Production Synthesis Orchestrator.
 * Validates Builds 801–810 across AegisHalfSwordBraceComponent, AegisCrownGuardCounterBindAbility, DevilsBargainChillingSilenceSubsystem, DevilsBargainHesitationProtocolEvaluator, AegisDefensiveArsenalAutomationTest, TrinityDoctrineGarrettInterceptDirector, TrinityDoctrineSerafinaPurificationDirector, WhiteFlameEyeFlareVFXAnchorActor, ShadowMarkRuneEtchVisualLocusActor, and Milestone 810 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone810MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone810")
	void RunMilestone810SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone810")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone810")
	bool bSynthesisPassComplete = false;
};
