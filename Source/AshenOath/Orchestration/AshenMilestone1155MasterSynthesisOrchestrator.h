// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1155MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1155MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1155 Production Synthesis across all 1,155 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1155MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1155Synthesis();

private:
	bool bMasterMilestone1155Validated = false;
};
