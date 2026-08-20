// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1730SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1730SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1730 Null Zone & Corruption core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1730SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1730Synthesis();
private:
	bool bMilestone1730Validated = false;
};
