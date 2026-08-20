// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1360SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1360SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1360 Companion Dialogue tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1360SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1360Synthesis();
private:
	bool bMilestone1360Validated = false;
};
