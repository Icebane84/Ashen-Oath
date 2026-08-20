// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1210SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1210SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1210 Memory Battles & Psychic Projections verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1210SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1210Synthesis();

private:
	bool bMilestone1210Validated = false;
};
