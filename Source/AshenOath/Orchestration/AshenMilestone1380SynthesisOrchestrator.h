// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1380SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1380SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1380 Execution Flourish tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1380SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1380Synthesis();
private:
	bool bMilestone1380Validated = false;
};
