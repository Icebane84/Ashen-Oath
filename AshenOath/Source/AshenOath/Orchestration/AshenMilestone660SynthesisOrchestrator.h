// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone660SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone660SynthesisOrchestrator
 *
 * Milestone 660 Production Synthesis Orchestrator.
 * Validates Builds 656–660 across AegisWhiteFlameDefensiveComponent, DevilsBargainTransformationSubsystem, WillpowerRewardMatrixSubsystem, and TrinityDoctrineCompanionSynergyComponent.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone660SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone660")
	void RunMilestone660SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone660")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone660")
	bool bSynthesisPassComplete = false;
};
