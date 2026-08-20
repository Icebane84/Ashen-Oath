// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1300SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1300SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1300 Living Oath tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1300SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1300Synthesis();
private:
	bool bMilestone1300Validated = false;
};
