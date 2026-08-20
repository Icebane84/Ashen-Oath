// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1710SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1710SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1710 Character Finisher GAS core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1710SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1710Synthesis();
private:
	bool bMilestone1710Validated = false;
};
