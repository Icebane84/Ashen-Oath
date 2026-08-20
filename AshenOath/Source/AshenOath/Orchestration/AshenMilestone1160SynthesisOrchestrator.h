// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1160SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1160SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1160 Psychological Operating System (UMB-UI-002) verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1160SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1160Synthesis();

private:
	bool bMilestone1160Validated = false;
};
