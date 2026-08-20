// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1395MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1395MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1395 Production Synthesis across all 1,395 builds.
 * Validates the complete Execution Flourish & Finisher Pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1395MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1395Synthesis();
private:
	bool bMasterMilestone1395Validated = false;
};
