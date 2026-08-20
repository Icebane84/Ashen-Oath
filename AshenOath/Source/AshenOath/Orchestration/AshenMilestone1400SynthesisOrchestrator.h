// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1400SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1400SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1400 Soul Rehabilitation tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1400SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1400Synthesis();
private:
	bool bMilestone1400Validated = false;
};
