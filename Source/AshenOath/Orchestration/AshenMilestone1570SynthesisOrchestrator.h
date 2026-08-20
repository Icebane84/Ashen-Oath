// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1570SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1570SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1570 Campfire Rest core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1570SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1570Synthesis();
private:
	bool bMilestone1570Validated = false;
};
