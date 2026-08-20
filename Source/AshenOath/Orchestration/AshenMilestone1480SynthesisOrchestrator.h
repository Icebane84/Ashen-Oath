// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1480SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1480SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1480 Unreliable Narrator tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1480SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1480Synthesis();
private:
	bool bMilestone1480Validated = false;
};
