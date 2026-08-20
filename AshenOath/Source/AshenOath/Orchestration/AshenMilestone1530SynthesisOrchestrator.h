// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1530SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1530SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1530 Boss Inquisition core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1530SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1530Synthesis();
private:
	bool bMilestone1530Validated = false;
};
