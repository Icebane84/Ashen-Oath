// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1675MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1675MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1675 Production Synthesis across all 1,675 builds.
 * Validates the complete Living Oath & Oathbringer Inner Mindscape Pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1675MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1675Synthesis();
private:
	bool bMasterMilestone1675Validated = false;
};
