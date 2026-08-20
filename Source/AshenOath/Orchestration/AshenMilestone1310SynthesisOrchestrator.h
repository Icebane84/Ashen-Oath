// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1310SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1310SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1310 Living Oath core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1310SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1310Synthesis();
private:
	bool bMilestone1310Validated = false;
};
