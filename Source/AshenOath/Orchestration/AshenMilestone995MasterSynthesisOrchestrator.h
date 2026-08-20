// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone995MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone995MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 995 Production Synthesis across all 995 builds.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone995MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone995Synthesis();

private:
	bool bMasterMilestone995Validated = false;
};
