// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1170SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1170SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1170 Single-Question Hub & ViewModels verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1170SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1170Synthesis();

private:
	bool bMilestone1170Validated = false;
};
