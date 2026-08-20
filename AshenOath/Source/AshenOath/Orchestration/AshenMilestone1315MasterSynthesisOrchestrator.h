// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1315MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1315MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1315 Production Synthesis across all 1,315 builds.
 * Validates the complete Living Oath Engine & FOathRecord Registry pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1315MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1315Synthesis();
private:
	bool bMasterMilestone1315Validated = false;
};
