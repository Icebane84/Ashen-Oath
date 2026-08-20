// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone990SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone990SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 990 Somatic Armor Corrosion & Companion Synergy verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone990SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone990Synthesis();

private:
	bool bMilestone990Validated = false;
};
