// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1370SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1370SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1370 Companion Dialogue core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1370SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1370Synthesis();
private:
	bool bMilestone1370Validated = false;
};
