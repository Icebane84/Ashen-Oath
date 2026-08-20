// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1595MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1595MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1595 Production Synthesis across all 1,595 builds.
 * Validates the complete Shroud Knight & Inquisitorial Purifiers Pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1595MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1595Synthesis();
private:
	bool bMasterMilestone1595Validated = false;
};
