// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone975MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone975MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 975 Production Synthesis across all 975 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone975MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone975Synthesis();

private:
	bool bMasterMilestone975Validated = false;
};
