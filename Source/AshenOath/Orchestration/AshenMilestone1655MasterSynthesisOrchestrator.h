// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1655MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1655MasterSynthesisOrchestrator
 * Master World Subsystem orchestrating Master Milestone 1655 Production Synthesis across all 1,655 builds.
 * Validates the complete Bestiary & Labyrinth Bespoke Finisher Pipeline (18 Archetypes).
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1655MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMasterMilestone1655Synthesis();
private:
	bool bMasterMilestone1655Validated = false;
};
