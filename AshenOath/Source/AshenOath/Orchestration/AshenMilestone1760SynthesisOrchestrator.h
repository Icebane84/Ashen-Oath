// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1760SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1760SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1760 Companion Fatigue & Divergence tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1760SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1760Synthesis();
private:
	bool bMilestone1760Validated = false;
};
