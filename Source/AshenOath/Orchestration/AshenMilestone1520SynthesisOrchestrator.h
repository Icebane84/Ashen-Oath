// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1520SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1520SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1520 Boss Inquisition tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1520SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1520Synthesis();
private:
	bool bMilestone1520Validated = false;
};
