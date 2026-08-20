// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone335SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone335SynthesisOrchestrator
 *
 * Milestone 335 Production Synthesis Orchestrator.
 * Validates Builds 321–335 across ResonanceWeaving, CorruptedCadenceBacklash, TSC, BurdenOfCommand, MartyrsTithe, SoulRemnants, VigilTravel, OrderHostility, NightmareLabyrinth, and WhisperingWinds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone335SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone335")
	void RunMilestone335SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone335")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone335")
	bool bSynthesisPassComplete = false;
};
