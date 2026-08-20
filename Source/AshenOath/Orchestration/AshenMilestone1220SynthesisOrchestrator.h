// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1220SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1220SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1220 Duality Engine & Dynamic Shader Shift verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1220SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1220Synthesis();

private:
	bool bMilestone1220Validated = false;
};
