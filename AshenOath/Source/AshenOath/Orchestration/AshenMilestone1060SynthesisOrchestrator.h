// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1060SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1060SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1060 Somatic Veil Phase Dissonance Filters verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1060SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1060Synthesis();

private:
	bool bMilestone1060Validated = false;
};
