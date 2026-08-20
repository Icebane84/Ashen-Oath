// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1020SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1020SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1020 Living Journal & Shared Memory Pipeline verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1020SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1020Synthesis();

private:
	bool bMilestone1020Validated = false;
};
