// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1450SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1450SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1450 Garrett Tactical core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1450SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1450Synthesis();
private:
	bool bMilestone1450Validated = false;
};
