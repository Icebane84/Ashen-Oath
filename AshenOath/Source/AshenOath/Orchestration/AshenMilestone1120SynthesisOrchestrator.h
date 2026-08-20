// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1120SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1120SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1120 Cartographer Map & MVVM Decoupled Pipeline verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1120SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1120Synthesis();

private:
	bool bMilestone1120Validated = false;
};
