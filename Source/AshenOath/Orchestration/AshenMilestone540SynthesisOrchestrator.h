// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone540SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone540SynthesisOrchestrator
 *
 * Milestone 540 Production Synthesis Orchestrator.
 * Validates Builds 536–540 across AlchemicalLanternComponent, AlchemicalTrapActor, AscensionChamberVolume, AudioOcclusionComponent, and Milestone 540 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone540SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone540")
	void RunMilestone540SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone540")
	int32 TotalBuildsCovered = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone540")
	bool bSynthesisPassComplete = false;
};
