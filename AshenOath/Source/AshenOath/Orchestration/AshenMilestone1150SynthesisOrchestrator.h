// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1150SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1150SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1150 White Flame Resolution & Crisis Dual Resolution verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1150SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1150Synthesis();

private:
	bool bMilestone1150Validated = false;
};
