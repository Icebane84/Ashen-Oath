// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1390SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1390SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1390 Execution Flourish core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1390SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1390Synthesis();
private:
	bool bMilestone1390Validated = false;
};
