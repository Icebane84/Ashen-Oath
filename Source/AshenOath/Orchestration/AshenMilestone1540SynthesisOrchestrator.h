// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1540SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1540SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1540 Alchemical Ecology tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1540SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1540Synthesis();
private:
	bool bMilestone1540Validated = false;
};
