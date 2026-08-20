// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1290SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1290SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1290 Companion Synergy core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1290SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1290Synthesis();
private:
	bool bMilestone1290Validated = false;
};
