// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone960SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone960SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 960 Mindscape Fracture & Somatic Posture verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone960SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone960Synthesis();

private:
	bool bMilestone960Validated = false;
};
