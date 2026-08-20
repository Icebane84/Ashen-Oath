// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1640SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1640SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1640 Bestiary Finisher tooling verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1640SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1640Synthesis();
private:
	bool bMilestone1640Validated = false;
};
