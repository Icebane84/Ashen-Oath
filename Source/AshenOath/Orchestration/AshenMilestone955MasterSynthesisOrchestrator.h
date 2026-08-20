// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone955MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone955MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 955 Production Synthesis across all 955 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone955MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone955Synthesis();

private:
	bool bMasterMilestone955Validated = false;
};
