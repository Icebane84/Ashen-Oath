// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1770SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1770SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1770 Companion Fatigue & Resonance core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1770SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1770Synthesis();
private:
	bool bMilestone1770Validated = false;
};
