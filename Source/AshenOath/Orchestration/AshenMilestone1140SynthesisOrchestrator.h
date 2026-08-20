// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1140SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1140SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1140 Devil's Bargain & Staggered Crisis Timeline verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1140SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1140Synthesis();

private:
	bool bMilestone1140Validated = false;
};
