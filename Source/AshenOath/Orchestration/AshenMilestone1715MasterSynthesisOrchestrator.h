// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1715MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1715MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1715 Production Synthesis across all 1,715 builds.
 * Validates the complete Character-Specific Finisher GAS Abilities & Socket Motion Warping Pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1715MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1715Synthesis();
private:
	bool bMasterMilestone1715Validated = false;
};
