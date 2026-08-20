// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1620SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1620SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1620 Party Finisher tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1620SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1620Synthesis();
private:
	bool bMilestone1620Validated = false;
};
