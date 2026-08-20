// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1440SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1440SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1440 Garrett Tactical Tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1440SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1440Synthesis();
private:
	bool bMilestone1440Validated = false;
};
