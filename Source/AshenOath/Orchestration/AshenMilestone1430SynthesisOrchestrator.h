// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1430SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1430SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1430 Wayfarer's Journal core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1430SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1430Synthesis();
private:
	bool bMilestone1430Validated = false;
};
