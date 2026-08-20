// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone980SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone980SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 980 Veil Phase Dissonance & Armor Corrosion verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone980SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone980Synthesis();

private:
	bool bMilestone980Validated = false;
};
