// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1115MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1115MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1115 Production Synthesis across all 1,115 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1115MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1115Synthesis();

private:
	bool bMasterMilestone1115Validated = false;
};
