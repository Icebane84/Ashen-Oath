// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone330SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone330SynthesisOrchestrator
 *
 * Milestone 330 Production Synthesis Orchestrator.
 * Validates Builds 321–330 across ResonanceWeaving, CorruptedCadenceBacklash, TSC, BurdenOfCommand, MartyrsTithe, SoulRemnants, VigilTravel, and OrderHostility.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone330SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone330")
	void RunMilestone330SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone330")
	int32 TotalBuildsCovered = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone330")
	bool bSynthesisPassComplete = false;
};
