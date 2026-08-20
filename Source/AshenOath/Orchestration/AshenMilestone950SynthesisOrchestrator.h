// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone950SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone950SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 950 Tactical Formation & Somatic Integration verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone950SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone950Synthesis();

private:
	bool bMilestone950Validated = false;
};
