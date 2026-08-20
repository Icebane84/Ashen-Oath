// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1720SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1720SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1720 Null Zone tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1720SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1720Synthesis();
private:
	bool bMilestone1720Validated = false;
};
