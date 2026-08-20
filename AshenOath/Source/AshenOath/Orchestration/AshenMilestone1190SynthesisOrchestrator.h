// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1190SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1190SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1190 StateTree Evaluators & Probabilistic Input Reading verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1190SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1190Synthesis();

private:
	bool bMilestone1190Validated = false;
};
