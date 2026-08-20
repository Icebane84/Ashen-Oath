// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1700SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1700SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1700 Character Finisher GAS tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1700SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1700Synthesis();
private:
	bool bMilestone1700Validated = false;
};
