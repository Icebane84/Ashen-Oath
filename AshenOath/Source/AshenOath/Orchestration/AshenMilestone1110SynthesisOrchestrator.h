// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1110SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1110SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1110 Grand Master Production Synthesis verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1110SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1110Synthesis();

private:
	bool bMilestone1110Validated = false;
};
