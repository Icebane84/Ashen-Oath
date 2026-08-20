// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone940SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone940SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 940 Hazard Safety & Somatic Corruption verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone940SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone940Synthesis();

private:
	bool bMilestone940Validated = false;
};
