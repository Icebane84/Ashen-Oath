// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1180SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1180SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1180 Cognitive AI & StateTree Task verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1180SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1180Synthesis();

private:
	bool bMilestone1180Validated = false;
};
