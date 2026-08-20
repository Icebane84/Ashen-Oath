// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1280SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1280SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1280 Companion Trust tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1280SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1280Synthesis();
private:
	bool bMilestone1280Validated = false;
};
