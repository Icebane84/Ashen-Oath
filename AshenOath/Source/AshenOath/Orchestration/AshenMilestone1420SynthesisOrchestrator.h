// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1420SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1420SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1420 Wayfarer's Journal tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1420SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1420Synthesis();
private:
	bool bMilestone1420Validated = false;
};
