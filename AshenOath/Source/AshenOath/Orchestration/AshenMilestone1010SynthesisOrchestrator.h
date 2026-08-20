// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1010SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1010SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1010 Sovereign Phoenix Synthesis verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1010SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1010Synthesis();

private:
	bool bMilestone1010Validated = false;
};
