// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1670SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1670SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1670 Living Oath core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1670SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1670Synthesis();
private:
	bool bMilestone1670Validated = false;
};
