// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1230SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1230SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1230 Modular Geometry & Corruption Mask Interpolator verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1230SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1230Synthesis();

private:
	bool bMilestone1230Validated = false;
};
