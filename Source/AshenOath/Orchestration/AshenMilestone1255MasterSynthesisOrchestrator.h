// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1255MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1255MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1255 Production Synthesis across all 1,255 builds.
 * Validates the complete MVSC Soul Constellation Kernel pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1255MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1255Synthesis();
private:
	bool bMasterMilestone1255Validated = false;
};
