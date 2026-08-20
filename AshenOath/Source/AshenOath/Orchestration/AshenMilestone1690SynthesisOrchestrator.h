// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1690SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1690SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1690 Memory Battle core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1690SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1690Synthesis();
private:
	bool bMilestone1690Validated = false;
};
