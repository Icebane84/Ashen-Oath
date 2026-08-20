// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone1350SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone1350SynthesisOrchestrator
 * World Subsystem orchestrating Milestone 1350 Duality Shader core systems verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone1350SynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone1350Synthesis();
private:
	bool bMilestone1350Validated = false;
};
