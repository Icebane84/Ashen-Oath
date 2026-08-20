// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1320SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1320SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1320 Memory Battle tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1320SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1320Synthesis();
private:
	bool bMilestone1320Validated = false;
};
