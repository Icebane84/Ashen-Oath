// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1680SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1680SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1680 Memory Battle tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1680SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1680Synthesis();
private:
	bool bMilestone1680Validated = false;
};
