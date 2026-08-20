// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1215MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1215MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1215 Production Synthesis across all 1,215 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1215MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1215Synthesis();

private:
	bool bMasterMilestone1215Validated = false;
};
