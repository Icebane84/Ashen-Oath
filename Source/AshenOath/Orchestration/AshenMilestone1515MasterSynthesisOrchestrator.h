// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1515MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1515MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1515 Production Synthesis across all 1,515 builds.
 * Validates the complete Advanced Combat GAS Abilities & Parry-Counter Execution Pipeline.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1515MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1515Synthesis();
private:
	bool bMasterMilestone1515Validated = false;
};
