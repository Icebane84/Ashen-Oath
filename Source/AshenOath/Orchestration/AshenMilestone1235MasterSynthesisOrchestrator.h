// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1235MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1235MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1235 Production Synthesis across all 1,235 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1235MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1235Synthesis();

private:
	bool bMasterMilestone1235Validated = false;
};
