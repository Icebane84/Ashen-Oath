// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1575MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1575MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1575 Production Synthesis across all 1,575 builds.
 * Validates the complete Campfire Rest Area & Heartstone Crucible Pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1575MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1575Synthesis();
private:
	bool bMasterMilestone1575Validated = false;
};
