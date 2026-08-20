// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1330SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1330SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1330 Memory Battle core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1330SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1330Synthesis();
private:
	bool bMilestone1330Validated = false;
};
