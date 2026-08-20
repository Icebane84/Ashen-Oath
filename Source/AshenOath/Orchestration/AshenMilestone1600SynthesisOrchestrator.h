// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1600SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1600SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1600 Somatic Telemetry tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1600SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1600Synthesis();
private:
	bool bMilestone1600Validated = false;
};
